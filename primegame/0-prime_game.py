#!/usr/bin/python3
"""
Prime Game - Maria et Ben jouent à un jeu. Étant donné un ensemble
d'entiers consécutifs allant de 1 à n inclus, ils choisissent à tour
de rôle un nombre premier dans l'ensemble et retirent ce nombre et ses
multiples de l'ensemble. Le joueur qui ne peut pas jouer perd la partie.
"""


def isWinner(x, nums):
    """
    Détermine le joueur qui a remporté le plus de rondes dans le jeu de prime
    où Maria et Ben choisissent des nombres premiers de manière optimale.

    :param x: Le nombre de rondes jouées.
    :param nums: Une liste contenant les valeurs de `n` pour chaque ronde.
    :return: Le nom du joueur ayant remporté le plus de rondes. Si c'est une égalité, retourne `None`.
    """
    if x <= 0 or not nums:
        return None

    def sieve_of_eratosthenes(n):
        """Retourne une liste de nombres premiers jusqu'à n."""
        sieve = [True] * (n + 1)
        sieve[0] = sieve[1] = False
        for i in range(2, int(n**0.5) + 1):
            if sieve[i]:
                for j in range(i * i, n + 1, i):
                    sieve[j] = False
        return [i for i, is_prime in enumerate(sieve) if is_prime]

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n <= 1:
            ben_wins += 1
            continue

        primes = sieve_of_eratosthenes(n)
        primes_set = set(primes)  # Pour un accès rapide

        turn = 0  # 0 pour Maria, 1 pour Ben
        while primes_set:
            # Joueur actuel choisit un premier
            chosen_prime = min(primes_set)  # Choix optimal : le plus petit
            primes_set -= set(range(chosen_prime, n + 1, chosen_prime))
            turn = 1 - turn  # Passer au joueur suivant

        # Si le dernier joueur était Ben, Maria a perdu
        if turn == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
