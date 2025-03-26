/*
    Documentation section
    @Project Exercice1 TP 
    @Author Meldi AHISSOU
    @Created 20250326
    @Program Description, functions
*/

//Link section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h> 
#include <stdbool.h>
typedef struct maillon
{
    int val;
    struct maillon *p_suiv;
} maillon_int;

//Definition section

//Global declaration section

//Function prototype declaration section

//Main function

//Sub functions

/* Initialise un élément de liste avec une valeur aléatoire entre 1 et 20
@input : void
@output : maillon_int*, pointeur sur le nouvel élément créé
@precondition : L'allocation mémoire réussit
@postcondition : Retourne un élément initialisé */
maillon_int *init_elt()
{
    
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int)); // Alloue de la mémoire pour un nouvel élément de la liste
    p_nv_elt->val = rand() % 20 + 1;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
} 

/* Ajoute un élément en tête de liste (version 1)
@input : maillon_int* p_tete,  tête de liste actuelle
         maillon_int* p_nv_elt, nouvel élément à ajouter
@output : maillon_int*, nouvelle tête de liste
@precondition : p_nv_elt doit être non NULL
@postcondition : L'élément est ajouté en tête de liste */
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

/* Ajoute un élément en tête de liste (version 2, passage par adresse)
@input : maillon_int** p_p_tete, adresse du pointeur de tête
         maillon_int* p_nv_elt, nouvel élément à ajouter
@output : void
@precondition : p_nv_elt doit être non NULL
@postcondition : L'élément est ajouté en tête de liste */
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}

/* Ajoute un élément en tête de liste avec gestion d'erreur
@input : maillon_int** p_p_tete, adresse du pointeur de tête
         maillon_int* p_nv_elt, nouvel élément à ajouter
@output : int, code d'erreur (0 si succès, -1 si échec)
@precondition : Aucune
@postcondition : L'élément est ajouté si p_nv_elt est non NULL */
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt)
{
    int errorCode = -1; 
    if (p_nv_elt != NULL) // Vérifier si le nouvel élément n'est pas NULL
    {
        p_nv_elt->p_suiv = *p_p_tete; // Lier le nouvel élément à la tête de liste actuelle
        *p_p_tete = p_nv_elt; // Mettre à jour la tête de liste pour qu'elle pointe sur le nouvel élément
        errorCode = 0; 
    }
    return errorCode; 
}

/* Affiche les éléments de la liste
@input : maillon_int* p_tete, pointeur sur la tête de liste
@output : void
@precondition : Aucune
@postcondition : La liste est affichée */
void parcourir(maillon_int *p_tete)
{
    if (p_tete == NULL)
        printf("liste vide"); 
    else
        while (p_tete != NULL)
        {
            printf("%d--", p_tete->val); // Affiche la valeur de l'élément courant
            p_tete = p_tete->p_suiv; // Passe à l'élément suivant
        }
    putchar('\n'); 
}

/* Insère un élément dans la liste triée par ordre croissant
@input : maillon_int* p_tete, tête de la liste
         maillon_int* p_nv_elt, nouvel élément à insérer
@output : maillon_int*, nouvelle tête de la liste
@precondition : p_nv_elt est non NULL
@postcondition : L'élément est inséré à la bonne position selon l'ordre croissant */
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt)
{
    maillon_int *n, *prec;

    // Si la liste est vide ou si la valeur de l'élément à insérer est inférieure ou égale à la valeur du premier élément
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val)
    {
        p_nv_elt->p_suiv = p_tete; // L'élément à insérer devient le premier élément
        p_tete = p_nv_elt; // Met à jour la tête de liste
    }
    else
    {
        n = prec = p_tete;
        // Parcourt la liste jusqu'à trouver la position d'insertion
        while (n != NULL && p_nv_elt->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n; // Insère l'élément à la bonne position
        prec->p_suiv = p_nv_elt; // Met à jour le pointeur du précédent élément
    }
    return p_tete;
}

/* Insère un élément dans la liste triée par ordre croissant (passage par adresse)
@input : maillon_int** prem, adresse du pointeur de tête
         maillon_int* e, nouvel élément à insérer
@output : void
@precondition : e est non NULL
@postcondition : L'élément est inséré à la bonne position selon l'ordre croissant */
void inserer2(maillon_int **prem, maillon_int *e)
{
    maillon_int *n, *prec;
    // Si la liste est vide ou si la valeur de l'élément à insérer est inférieure ou égale à la valeur du premier élément
    if (*prem == NULL || e->val <= (*prem)->val)
    {
        e->p_suiv = *prem; // L'élément à insérer devient le premier élément
        *prem = e; // Met à jour la tête de liste
    }
    else
    {
        n = prec = *prem; 
        // Parcourt la liste jusqu'à trouver la position d'insertion
        while (n != NULL && e->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n; // Insère l'élément à la bonne position
        prec->p_suiv = e; // Met à jour le pointeur du précédent élément
    }
}

/* Supprime l'élément de tête de la liste
@input : maillon_int** prem, adresse du pointeur de tête
@output : void
@precondition : Liste potentiellement non vide
@postcondition : L'élément de tête est supprimé si la liste n'est pas vide */
void supprimer_debut(maillon_int **prem)
{
    maillon_int *n;
    if (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv; // Met à jour la tête de liste pour pointer sur l'élément suivant
        free(n); 
    }
}

/* Supprime toutes les occurrences d'une valeur donnée dans la liste
@input : maillon_int** prem, adresse du pointeur de tête
         int valeur, valeur à supprimer
@output : void
@precondition : Liste potentiellement non vide
@postcondition : Tous les éléments de valeur égale à `valeur` sont supprimés */
void supprimer_elt(maillon_int **prem, int valeur)
{
    maillon_int *current = *prem;
    maillon_int *prev = NULL;
    
    while (current != NULL)
    {
        if (current->val == valeur)
        {   
            if (prev == NULL) // Si l'élément à supprimer est le premier de la liste
            {
                *prem = current->p_suiv;
                free(current);
                current = *prem;
            }
            else // Si l'élément à supprimer est au milieu ou à la fin de la liste
            {

                prev->p_suiv = current->p_suiv;
                free(current);
                current = prev->p_suiv;
            }
        }
        else // Avancer dans la liste
        {
            prev = current;
            current = current->p_suiv;
        }
    }
}


/* Détruit entièrement la liste
@input : maillon_int** prem, adresse du pointeur de tête
@output : void
@precondition : Aucune
@postcondition : Tous les éléments de la liste sont libérés */
void detruire_liste(maillon_int **prem)
{
    maillon_int *n;
    // Parcourt la liste jusqu'à ce qu'elle soit vide
    while (*prem != NULL)
    {
        n = *prem; 
        *prem = (*prem)->p_suiv; // Met à jour la tête de liste pour pointer sur l'élément suivant
        free(n); 
    }
}

/* Détruit entièrement la liste en utilisant `supprimer_debut`
@input : maillon_int** prem, adresse du pointeur de tête
@output : void
@precondition : Aucune
@postcondition : Tous les éléments de la liste sont libérés */
void detruire_liste2(maillon_int **prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int *prem)
{
    // ouvrir un fichier binaire en écriture : suffixe b
    FILE *f = fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n", f);
    // si liste non vide
    if (prem != NULL)
    {
        if (f == NULL)
            fprintf(stderr, "erreur création fichier :%i\n", errno);
        else // parcourir la liste jusque fin
            while (prem != NULL)
            {
                // écrire chaque maillon en binaire
                if (1 != fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr, "Erreur d'écriture du maillon %p\n", prem);
                else
                    // passer au maillon suivant
                    prem = prem->p_suiv;
            }
        fclose(f); // fermer le fichier
    }
    else
        fprintf(stderr, "pas de sauvegarde pour une liste vide\n");
}

/* Charge une liste depuis un fichier binaire "saveliste.bin"
@input : void
@output : maillon_int*, pointeur sur la tête de la liste chargée
@precondition : Le fichier doit exister et contenir une liste valide
@postcondition : Retourne la liste des éléments stockés dans le fichier */
maillon_int *load_liste()
{
    FILE *f; 
    maillon_int *prem = NULL, *p, e; 
    if ((f = fopen("saveliste.bin", "rb")) != NULL) // Ouverture du fichier binaire en lecture
    {
        prem = malloc(sizeof(maillon_int)); 
        fread(prem, sizeof(maillon_int), 1, f); // Lecture du premier élément depuis le fichier
        p = prem; 
        while (fread(&e, sizeof(maillon_int), 1, f)) // Lecture des éléments suivants jusqu'à la fin du fichier
        {
            p->p_suiv = malloc(sizeof(maillon_int)); 
            p = p->p_suiv; 
            *p = e; 
            p->p_suiv = NULL; 
        }
        fclose(f); // Fermeture du fichier
    }
    else
        printf("erreur ou fichier inexistant");
    return prem; 
}


/* Vérifie si la liste est vide
@input : maillon_int* prem, pointeur sur la tête de liste
@output : bool, true si la liste est vide, false sinon
@precondition : Aucune
@postcondition : Retourne true si la liste est vide, false sinon */
bool is_list_empty(maillon_int *prem)
{
    return (prem == NULL);
}


/* Récupère la valeur de l'élément de sommet de liste
@input : maillon_int* prem, pointeur sur la tête de liste
@output : int, valeur de l'élément de sommet de liste
@precondition : La liste n'est pas vide
@postcondition : Retourne la valeur de l'élément de sommet de pile */
int sommet_list(maillon_int *prem)
{
    if (prem == NULL)
    {
        fprintf(stderr, "Erreur: la liste est vide\n");
        return 1;
    }
    return prem->val;
}

/* Récupère la valeur et enlève l'élément de sommet de pile
@input : maillon_int** prem, adresse du pointeur de tête de liste
@output : int, valeur de l'élément de sommet de pile
@precondition : La liste n'est pas vide
@postcondition : Retourne la valeur de l'élément de sommet de pile et enlève cet élément de la liste */
int retirer_sommet_list(maillon_int **prem)
{
    // Vérifie si la liste est vide
    if (*prem == NULL)
    {
        fprintf(stderr, "Erreur: la liste est vide\n");
        return 1;
    }

    int val = (*prem)->val;
    // Sauvegarde le pointeur de l'élément de sommet
    maillon_int *temp = *prem;
    // Met à jour la tête de liste pour pointer sur l'élément suivant
    *prem = (*prem)->p_suiv;

    free(temp);
    
    return val;
}

/* Renverse et affiche une liste d'entiers en utilisant une pile
@input : maillon_int* p_tete, pointeur sur la tête de liste
@output : void
@precondition : Aucune
@postcondition : La liste est renversée et affichée */
void renverser_list(maillon_int *p_tete)
{
    maillon_int *pile = NULL;
    maillon_int *temp;

    // Parcourt la liste et empile chaque élément
    while (p_tete != NULL)
    {
        temp = p_tete;
        p_tete = p_tete->p_suiv;
        temp->p_suiv = pile;
        pile = temp;
    }

    // Affiche chaque élément de la pile (qui est maintenant une liste inversée)
    parcourir(pile);

    // Détruit la liste inversée
    detruire_liste(&pile);
}
