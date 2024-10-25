      Project: Making Change | Holberton Laval, France Intranet            Cookies.set('timezone', (new Date()).getTimezoneOffset() / -60.0);

Toggle navigation[

](/)

*   [

    Help

    ](https://students-support.hbtn.io/hc)
*   [

    Projects

    ](/projects/current)
*   [

    My reports

    ](/users/my_reports)
*   [

    QA Reviews I can make

    ](/corrections/to_review)
*   [

    Mock interviews

    ](/dashboards/my_current_reefineries)
*   [

    Evaluation quizzes

    ](/dashboards/my_current_evaluation_quizzes)

* * *

*   [

    Concepts

    ](/concepts)
*   [

    Servers

    ](/servers)
*   [

    Sandboxes

    ](/user_sandboxes)
*   [

    Tools

    ](/dashboards/my_tools)

* * *

*   [

    Peers

    ](/users/peers)
*   [

    Captain's Logs

    ](/dashboards/my_captain_log)
*   [

    Officers

    ](/dashboards/my_officers)
*   [

    Speakers of the Day

    ](/dashboards/my_speakers_of_the_day)

* * *

*   [

    Slack

    ](https://holberton-school-org.slack.com)

    [

    Search

    ](#)

    [

    My Profile

    ](/users/my_profile)


[

](/)

*   [

    Help

    ](https://students-support.hbtn.io/hc)
*   [

    Projects

    ](/projects/current)
*   [

    My reports

    ](/users/my_reports)
*   [

    QA Reviews I can make

    ](/corrections/to_review)
*   [

    Mock interviews

    ](/dashboards/my_current_reefineries)
*   [

    Evaluation quizzes

    ](/dashboards/my_current_evaluation_quizzes)

* * *

*   [

    Concepts

    ](/concepts)
*   [

    Servers

    ](/servers)
*   [

    Sandboxes

    ](/user_sandboxes)
*   [

    Tools

    ](/dashboards/my_tools)

* * *

*   [

    Peers

    ](/users/peers)
*   [

    Captain's Logs

    ](/dashboards/my_captain_log)
*   [

    Officers

    ](/dashboards/my_officers)
*   [

    Speakers of the Day

    ](/dashboards/my_speakers_of_the_day)

* * *

*   [

    Slack

    ](https://holberton-school-org.slack.com)

    [

    Search

    ](#)

    [

    My Profile

    ](/users/my_profile)


Curriculum

\[C#21\] Interview Preparation - Algorithms Average: 98.04%

*   [

    \[C#20\] Foundations v2 - Part 1 Average: 0.0%



    ](/curriculums/208/observe/27054)
*   [

    \[C#20\] Foundations v2 - Part 2 Average: 0.0%



    ](/curriculums/252/observe/27059)
*   [

    \[C#20\] Foundations v2 - Part 3 Average: 0.0%



    ](/curriculums/274/observe/27064)
*   [

    \[C#21\] Spe - Web Stack programming 2024 Average: 86.07%



    ](/curriculums/343/observe/37643)
*   [

    \[C#21\] Interview Preparation - Algorithms Average: 98.04%



    ](/curriculums/215/observe/37644)
*   [

    \[C#21\] Interview Preparation - Prepare Yourself Average: 99.43%



    ](/curriculums/219/observe/37645)

[

You have a captain's log due before 2024-10-27 (in 2 days)! Log it now!

](/captain_logs/211664/edit)

*   [Description](#description)

[Go to tasks](#)

Requirements
------------

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
*   All your files should end with a new line
*   The first line of all your files should be exactly `#!/usr/bin/python3`
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `PEP 8` style (version 1.7.x)
*   All your files must be executable

Tasks
-----

### 0\. Change comes from within

mandatory

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount `total`.

*   Prototype: `def makeChange(coins, total)`
*   Return: fewest number of coins needed to meet `total`
    *   If `total` is `0` or less, return `0`
    *   If `total` cannot be met by any number of coins you have, return `-1`
*   `coins` is a list of the values of the coins in your possession
*   The value of a coin will always be an integer greater than `0`
*   You can assume you have an infinite number of each denomination of coin in the list
*   Your solution’s runtime will be evaluated in this task


        carrie@ubuntu:~/making_change$ cat 0-main.py
        #!/usr/bin/python3
        """
        Main file for testing
        """

        makeChange = __import__('0-making_change').makeChange

        print(makeChange([1, 2, 25], 37))

        print(makeChange([1256, 54, 48, 16, 102], 1453))

        carrie@ubuntu:~/making_change$


        carrie@ubuntu:~/making_change$ ./0-main.py
        7
        -1
        carrie@ubuntu:~/making_change$



**Repo:**

*   GitHub repository: `holbertonschool-interview`
*   Directory: `making_change`
*   File: `0-making_change.py`

**0/20** pts
