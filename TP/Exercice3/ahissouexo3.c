/*
    Documentation section
    @Project Exercice3 TP 
    @Author Meldi AHISSOU
    @Created 20250326
    @Program Description, Program to start menu
*/

//Link section
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
typedef struct horaire_De_Train {
    char ville_depart[51];  
    char ville_arrivee[51]; 
    char heure_depart[6];   // Heure de départ (format HH:MM)
    char heure_arrivee[6];  // Heure d'arrivée (format HH:MM)
    int distance;           // je me base sur l'exemple
    struct horaire_De_Train *suivant; // Pointeur vers l'élément suivant
} horaire_De_Train;

//Definition section

//Global declaration section

//Function prototype declaration section
horaire_De_Train *ajouter_horaire(horaire_De_Train *tete);
void afficher_horaires(horaire_De_Train *tete);
void afficher_horaires_depart_de(horaire_De_Train *tete, char *ville);

//Main function
int main()
{
   /*
   
    Question 1:
        Il nous faudra une structure qui permet de rajouter et de supprimer des 
        horaires facilement.la structure permettra aussi de parcourir rapidement
        la liste des horaires afin de rechercher une horaire spécifique.La structure
        qui me semble la mieux adapté est donc une "Liste chaînée".
        
    Question 2: 
        horaire_De_Train *ajouter_Horaire(horaire_De_Train *tete);

    Question 3: 
        void afficher_horaires_depart_de(horaire_De_Train *tete, char *ville);

    Question 4:
        void affiche_horaire_vmoyMax(horaire_De_Train *tete);  



   */

   horaire_De_Train *liste_horaires = NULL;

   // Ajout de plusieurs horaires
   liste_horaires = ajouter_horaire(liste_horaires);
   printf("%s",liste_horaires);
   liste_horaires = ajouter_horaire(liste_horaires);

   // Affichage des horaires
   printf("\nListe des horaires enregistrés :\n");
//    afficher_horaires(liste_horaires);
    
    liberer_horaires(liste_horaires);
    return 0;
}


//Sub functions

// Fonction pour ajouter un horaire à la liste
horaire_De_Train *ajouter_horaire(horaire_De_Train *tete) {
    // Allocation mémoire pour un nouvel horaire
    horaire_De_Train *nouveau = (horaire_De_Train *)malloc(sizeof(horaire_De_Train));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return tete;
    }

    // Saisie des informations
    printf("Ville de départ : ");
    scanf("%50s", nouveau->ville_depart);
    printf("Ville d'arrivée : ");
    scanf("%50s", nouveau->ville_arrivee);
    printf("Heure de départ (HHhMM) : ");
    scanf("%5s", nouveau->heure_depart);
    printf("Heure d'arrivée (HHhMM) : ");
    scanf("%5s", nouveau->heure_arrivee);
    printf("Distance entre les villes (en km, nombre entier) : ");
    scanf("%d", &nouveau->distance);

    // Ajout du nouvel élément en tête de liste
    nouveau->suivant = tete;
    return nouveau;
}

// Fonction pour afficher les horaires de train
void afficher_horaires(horaire_De_Train *tete) {
    horaire_De_Train *courant = tete;
    while (courant != NULL) {
        printf("%s -> %s | Départ : %s | Arrivée : %s | Distance : %d km\n",
               courant->ville_depart, courant->ville_arrivee,
               courant->heure_depart, courant->heure_arrivee,
               courant->distance);
        courant = courant->suivant;
    }
}

void afficher_horaires_depart_de(horaire_De_Train *tete, char *ville){
    horaire_De_Train *courant = tete;
    int trouve = 0;
    
    printf("\nTrains au départ de %s :\n", ville);
    while (courant != NULL) {
        if (strcmp(courant->ville_depart, ville) == 0) {
            printf("-> %s | Départ : %s | Arrivée : %s | Distance : %d km\n",
                   courant->ville_arrivee, courant->heure_depart,
                   courant->heure_arrivee, courant->distance);
            trouve = 1;
        }
        courant = courant->suivant;
    }

    if (!trouve) {
        printf("Aucun train au départ de %s.\n", ville);
    }
}


void affiche_horaire_vmoyMax(horaire_De_Train *tete){
    horaire_De_Train *courant = tete;
    horaire_De_Train *trajet_vmoyMax;
    double vmoyMax = 0.0;

    /*
     il faudra que je calcule la vitesse moyenne de courant et que je 
     vérifie si elle est plus grande que vmoyMax. si oui elle devient vmoyMax et 
     trajet_vMoyMax récupère courant sinon vmoyMax reste intact. 
    */
    
}



void liberer_horaires(horaire_De_Train *tete) {
    horaire_De_Train *courant = tete;
    horaire_De_Train *suivant;

    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}
