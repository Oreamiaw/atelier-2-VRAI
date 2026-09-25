#include <stdio.h>
#include <stdlib.h>

int main() {
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;
    int ecartScore;

    printf("=== PIERRE - FEUILLE - CISEAUX (7 Manches) ===\n");
    printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux\n\n");

    while (manche <= 7) {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        printf("Votre choix (1, 2 ou 3) : ");
        scanf("%d", &choixJoueur);

        // Choix aléatoire de l'ordinateur (1, 2 ou 3)
        choixOrdi = (rand() % 3) + 1;

        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } else if ((choixJoueur == 1 && choixOrdi == 3) ||
                   (choixJoueur == 2 && choixOrdi == 1) ||
                   (choixJoueur == 3 && choixOrdi == 2)) {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        } else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);

        manche = manche + 1;
    }

    // Calcul de l'écart de score (valeur absolue)
    ecartScore = abs(scoreOrdi - scoreJoueur);

    // Bilan de la partie
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);
    printf("Écart de score : %d\n", ecartScore);

    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagné la partie !\n");
    } else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    } else {
        printf("Match nul parfait !\n");
    }

    return 0;
}