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
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int));
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
    if (p_nv_elt != NULL)
    {
        p_nv_elt->p_suiv = *p_p_tete;
        *p_p_tete = p_nv_elt;
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
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
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

    if (p_tete == NULL || p_nv_elt->val <= p_tete->val)
    {
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else
    {
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
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
    if (*prem == NULL || e->val <= (*prem)->val)
    {
        e->p_suiv = *prem;
        *prem = e;
    }
    else
    {
        n = prec = *prem;
        while (n != NULL && e->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
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
        *prem = (*prem)->p_suiv;
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
            if (prev == NULL)
            {
                *prem = current->p_suiv;
                free(current);
                current = *prem;
            }
            else
            {
                prev->p_suiv = current->p_suiv;
                free(current);
                current = prev->p_suiv;
            }
        }
        else
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
    while (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv;
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
    if ((f = fopen("saveliste.bin", "rb")) != NULL)
    {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f))
        {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}
