#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Count occurrences of given keywords in the titles of hot articles on a
    subreddit.

    :param subreddit: The name of the subreddit to query.
    :param word_list: A list of keywords to count occurrences of.
    :param after: A token for paginating results, indicating the starting point
    for the next page of results.
    :param word_count: A dictionary to store the word counts. Used for
    recursion, should not be supplied when calling the function.
    """

    if after is None:
        after = ''
    if word_count is None:
        word_count = {}

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'limit': '100', 'after': after} if after else {'limit': '100'}

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)
    if response.status_code != 200:
        print(f"Error fetching data from subreddit: {response.status_code}")
        return

    data = response.json()

    for post in data['data']['children']:
        title = post['data']['title'].lower()
        for word in word_list:
            count = title.count(word.lower())
            if count > 0:
                word_count[word.lower()] = word_count.get(
                    word.lower(), 0) + count

    next_page = data['data']['after']
    if next_page:
        return count_words(subreddit, word_list, after=next_page,
                           word_count=word_count)

    sorted_word_count = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_word_count:
        print(f"{word}: {count}")
