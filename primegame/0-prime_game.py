#!/usr/bin/python3


def sieve_of_eratosthenes(n):
    """Renvoie la liste des nombres premiers jusqu'à n en utilisant le crible
        d'Ératosthène.
    """
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False  # 0 et 1 ne sont pas des premiers
    for i in range(2, int(n**0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    return [i for i in range(2, n + 1) if primes[i]]


def isWinner(x, nums):
    """Renvoie le nom du joueur ayant gagné le plus de ronde"""
    maria_wins = 0
    ben_wins = 0

    # Parcours de chaque jeu
    for n in nums:
        if n == 1:
            ben_wins += 1  # Si n=1, Ben gagne car Maria ne peut pas jouer
            continue

        primes = sieve_of_eratosthenes(n)
        # Le nombre de primes disponibles déterminera le gagnant
        if len(primes) % 2 == 1:
            maria_wins += 1  # Si le nombre de primes est impair, Maria gagne
        else:
            ben_wins += 1  # Si le nombre de primes est pair, Ben gagne

    # Retourner le nom du gagnant
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
