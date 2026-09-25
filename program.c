#include <stdio.h>
#include <stdlib.h>

int main() {
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;
    int ecartScore;

    printf("=== PIERRE - FEUILLE - CISEAUX - LEZARD - SPOCK (7 Manches) ===\n");
    printf("Regles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lezard, 5 = Spock\n\n");

    while (manche <= 7) {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        printf("Votre choix (1 a 5) : ");
        scanf("%d", &choixJoueur);

        // Choix aleatoire de l'ordinateur (1 a 5)
        choixOrdi = (rand() % 5) + 1;

        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        // Determination du gagnant de la manche (10 combinaisons gagnantes)
        if (choixJoueur == choixOrdi) {
            printf("Egalite !\n");
        } else if ((choixJoueur == 1 && choixOrdi == 3) ||  // Pierre ecrase Ciseaux
                   (choixJoueur == 1 && choixOrdi == 4) ||  // Pierre ecrase Lezard
                   (choixJoueur == 2 && choixOrdi == 1) ||  // Feuille recouvre Pierre
                   (choixJoueur == 2 && choixOrdi == 5) ||  // Feuille refute Spock
                   (choixJoueur == 3 && choixOrdi == 2) ||  // Ciseaux coupent Feuille
                   (choixJoueur == 3 && choixOrdi == 4) ||  // Ciseaux decapitent Lezard
                   (choixJoueur == 4 && choixOrdi == 2) ||  // Lezard mange Feuille
                   (choixJoueur == 4 && choixOrdi == 5) ||  // Lezard empoisonne Spock
                   (choixJoueur == 5 && choixOrdi == 1) ||  // Spock vaporise Pierre
                   (choixJoueur == 5 && choixOrdi == 3)) {  // Spock desintegre Ciseaux
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        } else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);

        manche = manche + 1;
    }

    // Calcul de l'ecart de score (valeur absolue)
    ecartScore = abs(scoreOrdi - scoreJoueur);

    // Bilan de la partie
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);
    printf("Ecart de score : %d\n", ecartScore);

    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagne la partie !\n");
    } else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    } else {
        printf("Match nul parfait !\n");
    }

    return 0;
}