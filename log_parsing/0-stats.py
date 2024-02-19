#!/usr/bin/python3
import sys


def print_statistics(total_file_size, status_codes):
    """
    Fonction pour afficher les statistiques.

    Args:
        total_file_size (int): La taille totale des fichiers.
        status_codes (dict): Un dictionnaire contenant les codes de statut HTTP
                         comme clés et le nombre d'occurrences comme valeurs.
    """
    print(f"File size: {total_file_size}")
    for code, count in sorted(status_codes.items()):
        if count > 0:
            print(f"{code}: {count}")


def main():
    """
    Fonction principale du programme.
    """
    try:
        total_file_size = 0
        status_codes = {
            200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0
            }
        line_count = 0  # Initialisation du compteur de lignes

        for line in sys.stdin:
            parts = line.split()
            try:
                status_code = int(parts[-2])  # Convertir en entier
            except ValueError:
                continue  # Ignorer les lignes avec un code de statut invalide
            file_size = int(parts[-1])
            total_file_size += file_size
            status_codes[status_code] += 1

            # Incrémenter le compteur de lignes
            line_count += 1

            # Afficher le total de la taille des fichiers et les codes de
            # statut toutes les 10 lignes
            if line_count % 10 == 0:
                print_statistics(total_file_size, status_codes)

        # Afficher le total final de la taille des fichiers et les codes de
        # statut s'il reste des lignes
        if line_count % 10 != 0:
            print_statistics(total_file_size, status_codes)

    except KeyboardInterrupt:
        print_statistics(total_file_size, status_codes)
        sys.exit(0)


if __name__ == "__main__":
    main()
