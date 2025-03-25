/*
    Documentation section
    @Project TD1 B2 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, librairie util_rand.h 
*/ 
#ifndef UTIL_RAND_H
#define UTIL_RAND_H

//Link section
#include <stdlib.h>
#include <time.h>


// Initialise le générateur de nombres aléatoires
void init_random();
// Génère un nombre entier aléatoire avec la plage maximale du générateur
int random_int();

// Génère un nombre entier aléatoire entre 0 et "seuil_haut"
int random_int_max(int seuil_haut);

// Génère un nombre entier aléatoire entre "seuil_bas" et "seuil_haut"
int random_int_range(int seuil_bas, int seuil_haut);

// Génère un nombre réel aléatoire entre 0 et 1
double random_double();

// Génère un nombre réel à deux décimales entre "seuil_bas" et "seuil_haut"
double random_double_range(double seuil_bas, double seuil_haut);

#endif



