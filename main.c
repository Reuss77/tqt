#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grid[4][4];
    int i = 0, j = 0;
    int min_num, next_num;
    char direction;

    // Initialiser la grille avec des nombres aléatoires entre 1 et 9
    srand(time(NULL));
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            grid[i][j] = rand() % 8 + 1;
        }
    }

// Mettre le point de départ en haut à gauche de la grille
    grid[0][0] = 'x';

// Afficher la grille
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (grid[i][j] < 10) {  // Ajouter un espace pour les nombres à un seul chiffre
                printf(" ");
            }

            // Vérifier si le nombre est déjà trouvé et le colorier en bleu
            if (grid[i][j] == 'x') {
                printf("\033[1;34mx\033[0m ");
            } else if (grid[i][j] < min_num) {
                printf("\033[1;34m%d\033[0m ", grid[i][j]);
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }

// Boucle principale du jeu
    while (1) {
        // Demander à l'utilisateur de saisir une direction pour sélectionner le nombre suivant
        printf("Choisissez une direction (Z pour monter, S pour descendre, Q pour aller à gauche, D pour aller à droite) : ");
        scanf(" %c", &direction);

        // Choisir le nombre suivant en fonction de la direction choisie
        switch(direction) {
            case 'Z':
            case 'z':
                if (i > 0) {
                    i--;
                }
                break;
            case 'S':
            case 's':
                if (i < 3) {
                    i++;
                }
                break;
            case 'Q':
            case 'q':
                if (j > 0) {
                    j--;
                }
                break;
            case 'D':
            case 'd':
                if (j < 3) {
                    j++;
                }
                break;
            default:
                printf("Direction invalide. Essayez encore.\n");
                continue;
        }

        next_num = grid[i][j];

        // Vérifier si le nombre saisi est le suivant dans la séquence
        if (next_num == min_num) {
            printf("Bravo, vous avez trouve le nombre suivant !\n");
            min_num++;

            // Remplacer le nombre trouvé par 'x'
            grid[i][j] = 'x';

            // Colorier le nombre trouvé en bleu
            printf("\033[1;34mx\033[0m ");

            // Afficher la grille mise à jour avec le nombre trouvé colorié en bleu
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (grid[i][j] == 'x') {
                        printf("\033[34m%d\033[0m ", -grid[i][j]);
                    } else {
                        printf("%d ", grid[i][j]);
                    }
                }
                printf("\n");
            }

        }

        return 0;
