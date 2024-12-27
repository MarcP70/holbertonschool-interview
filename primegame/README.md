      Project: Prime Game | Holberton Laval, France Intranet            Cookies.set('timezone', (new Date()).getTimezoneOffset() / -60.0);

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

\[C#21\] Interview Preparation - Algorithms Average: 97.53%

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

    \[C#21\] Spe - Web Stack programming 2024 Average: 94.37%



    ](/curriculums/343/observe/37643)
*   [

    \[C#21\] Interview Preparation - Algorithms Average: 97.53%



    ](/curriculums/215/observe/37644)
*   [

    \[C#21\] Interview Preparation - Prepare Yourself Average: 99.56%



    ](/curriculums/219/observe/37645)
*   [

    \[C#21\] RNCP 6 - Parcours de préparation (V2) Average: %



    ](/curriculums/422/observe/47698)

[

You have a captain's log due before 2024-12-29 (in 2 days)! Log it now!

](/captain_logs/220599/edit)

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

### 0\. Prime Game

mandatory

Maria and Ben are playing a game. Given a set of consecutive integers starting from `1` up to and including `n`, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

They play `x` rounds of the game, where `n` may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.

*   Prototype: `def isWinner(x, nums)`
*   where `x` is the number of rounds and `nums` is an array of `n`
*   Return: name of the player that won the most rounds
*   If the winner cannot be determined, return `None`
*   You can assume `n` and `x` will not be larger than 10000
*   You cannot import any packages in this task

Example:

*   `x` = `3`, `nums` = `[4, 5, 1]`

First round: `4`

*   Maria picks 2 and removes 2, 4, leaving 1, 3
*   Ben picks 3 and removes 3, leaving 1
*   Ben wins because there are no prime numbers left for Maria to choose

Second round: `5`

*   Maria picks 2 and removes 2, 4, leaving 1, 3, 5
*   Ben picks 3 and removes 3, leaving 1, 5
*   Maria picks 5 and removes 5, leaving 1
*   Maria wins because there are no prime numbers left for Ben to choose

Third round: `1`

*   Ben wins because there are no prime numbers for Maria to choose

**Result: Ben has the most wins**

    carrie@ubuntu:~/primegame$ cat main_0.py
    #!/usr/bin/python3

    isWinner = __import__('0-prime_game').isWinner


    print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

    carrie@ubuntu:~/primegame$


    carrie@ubuntu:~/primegame$ ./main_0.py
    Winner: Ben
    carrie@ubuntu:~/primegame$


**Repo:**

*   GitHub repository: `holbertonschool-interview`
*   Directory: `primegame`
*   File: `0-prime_game.py`

**0/16** pts
