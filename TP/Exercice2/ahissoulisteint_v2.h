/*
    Documentation section
    @Project Exercice1 TP 
    @Author Meldi AHISSOU
    @Created 20250326
    @Program Description, declarations code
*/

//Link section
#include "ahissoulisteint_v2.c"



//Definition section

//Global declaration section

//Function prototype declaration section
maillon_int *init_elt();
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt);
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt);
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt);
void parcourir(maillon_int *p_tete);
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt);
void inserer2(maillon_int **prem, maillon_int *e);
void supprimer_debut(maillon_int **prem);
void supprimer_elt(maillon_int **prem, int valeur);
void detruire_liste(maillon_int **prem);
void detruire_liste2(maillon_int **prem);
void sauver_liste(maillon_int *prem);
maillon_int *load_liste();
bool is_list_empty(maillon_int *prem);
int sommet_list(maillon_int *prem);
int retirer_sommet_list(maillon_int **prem);
void renverser_list(maillon_int *p_tete);

//Main function

//Sub functions
