/*
    Documentation section
    @Project Exercice1 TP 
    @Author Meldi AHISSOU
    @Created 20250326
    @Program Description, Program to start menu
*/

//Link section
#include "ahissoulisteint.h"

//Definition section

//Global declaration section

//Function prototype declaration section
int menu();

//Main function
/* programme principal
@input : void
@output : int, code d'erreur (0 si succès, -1 si échec)
@precondition : 
@postcondition : l'opération voulu par l'utilisateur est effectuée */
int main()
{
    maillon_int *premier = NULL;
    maillon_int *nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {
        case 1: // Creer une liste de taille aleatoire
            nb = rand() % 20 + 1;
            for (int j = 0; j < nb; j++)
            {
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau);
            }
            parcourir(premier);
            break;

        case 2: // Ajouter un élément en tête
            nouveau = init_elt();
            ajout_tete_v2(&premier, nouveau);
            parcourir(premier);
            break;

        case 3: // Inserer (ordre croissant)
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            parcourir(premier);
            break;

        case 4: // Supprimer début
            supprimer_debut(&premier);
            parcourir(premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnée
            printf("Entrer la valeur à supprimer : ");
            scanf("%d", &nb);
            rewind(stdin);
            supprimer_elt(&premier, nb);
            parcourir(premier);
            break;

        case 6: // Détruire liste
            detruire_liste2(&premier);
            parcourir(premier);
            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            break;

        case 8: // Charger liste
            premier = load_liste();
            parcourir(premier);
            break;

        default:
            fin = 1;
            break;
        }
    }

    return 0;
}


//Sub functions
/* Affiche le menu et récupère le choix de l'utilisateur
@input : void
@output : int, choix de l'utilisateur
@precondition : Aucune
@postcondition : Un choix valide est retourné */
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    // Réinitialiser la position de lecture/écriture du flux standard d'entrée.
    rewind(stdin);

    return choix;
}
