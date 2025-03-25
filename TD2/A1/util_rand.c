/*
    Documentation section
    @Project TD2 A1 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, définition des fonctions 
*/ 

//Link section
#include "util_rand.h"

void init_random() {
    srand(time(NULL));
}

int random_int() {
    return rand();
}

int random_int_max(int seuil_haut) {
    return rand() % (seuil_haut + 1);
}

int random_int_range(int seuil_bas, int seuil_haut) {
    return seuil_bas + rand() % (seuil_haut - seuil_bas + 1);
}

double random_double() {
    return (double)rand() / RAND_MAX;
}

double random_double_range(double seuil_bas, double seuil_haut) {
    double scale = (double)rand() / RAND_MAX; 
    double result = seuil_bas + scale * (seuil_haut - seuil_bas);
    return (int)(result * 100) / 100.0; // Arrondi à 2 décimales
}
