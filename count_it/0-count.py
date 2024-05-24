import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    if word_count is None:
        word_count = {}

    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after} if after else {}

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return

        data = response.json()
        titles = [post['data']['title'] for post in data['data']['children']]

        for title in titles:
            words = title.lower().split()
            for word in words:
                cleaned_word = ''.join(filter(str.isalnum, word))
                if cleaned_word in word_list:
                    word_count[cleaned_word] = word_count.get(cleaned_word,
                                                            0) + 1

        after = data['data']['after']
        if after:
            count_words(subreddit, word_list, after, word_count)
        else:
            if word_count:
                sorted_counts = sorted(word_count.items(),
                                       key=lambda item: (-item[1], item[0]))
                for word, count in sorted_counts:
                    print(f'{word}: {count}')
    except Exception as e:
        pass
