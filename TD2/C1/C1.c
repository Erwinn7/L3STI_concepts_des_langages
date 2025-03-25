/*
    Documentation section
    @Project TD2 C1 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to sum a list of number 
*/ 

//Link section
#include <stdio.h>
#include <stdlib.h>


int produit_recursif(int n) ;
int produit_terminal(int n);
int produit_recursif_terminal(int n, int accumulateur);

//Main function
int main(int argc, char const *argv[])
{
    int n;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erreur : Le nombre doit être positif.\n");
        return 1;
    }

    printf("Produit récursif classique de %d : %lld\n", n, produit_recursif(n));
    printf("Produit récursif terminal de %d : %lld\n", n, produit_terminal(n));


    return 0;
}


// function 

// Récursivité classique
int produit_recursif(int n) {
    if (n <= 1) 
        return 1;
    return n * produit_recursif(n - 1);
}


// Récusivité avec accumulateur
int produit_terminal(int n) {
    return produit_recursif_terminal(n, 1);
}

int produit_recursif_terminal(int n, int accumulateur) {
    if (n <= 1) 
        return accumulateur;
    return produit_recursif_terminal(n - 1, n * accumulateur);
}