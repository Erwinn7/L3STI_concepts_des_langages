/*
    Documentation section
    @Project TD2 A1 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to sum a list of number 
*/ 

//Link section
#include <stdio.h>
#include "util_rand.h"

int main() {
    init_random(); // Initialisation du générateur

    printf("Nombre entier aléatoire: %d\n", random_int());
    printf("Nombre entier aléatoire [0, 50]: %d\n", random_int_max(50));
    printf("Nombre entier aléatoire [10, 100]: %d\n", random_int_range(10, 100));
    printf("Nombre réel aléatoire [0, 1]: %.4f\n", random_double());
    printf("Nombre réel aléatoire [1.5, 4.5] à 2 décimales: %.2f\n", random_double_range(1.5, 4.5));

    return 0;
}











