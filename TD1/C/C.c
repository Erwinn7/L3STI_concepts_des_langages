//  faire un tel programme avec scanf() n'est pas possible car scanf() ne 
// détecte pas en temps réelle les touches du clavier. il récupère les touches 
// après une validation ce qui mettrait le programme en pause le temps que 
// l'utilisateur écrive son caractère.


/*
    Documentation section
    @Project TD1 C2 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to continuously display zeros and repeat user input a random number of times
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input;
    int repeat;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    while (1) {
        // Afficher des zéros en continu
        for (int i = 0; i < 10; i++) { 
            printf("0\n");
        }

        printf("\nAppuyez sur une touche et validez avec Entrée : ");
        scanf(" %c", &input); // Attendre une touche

        // Générer un nombre aléatoire de répétitions
        repeat = rand() % 10 + 1; // Nombre aléatoire entre 1 et 10

        // Afficher la touche appuyée plusieurs fois
        for (int i = 0; i < repeat; i++) {
            printf("%c ", input);
        }
        printf("\n");
    }

    return 0;
}
