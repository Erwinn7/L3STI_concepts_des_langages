/*
    Documentation section
    @Project TD1 A4 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to show some character enter by the user 
*/ 

//Link section
#include <stdio.h>
#include <stdlib.h>

//Main function
int main()
{
    char char1, char2, char3;

    printf("Enter 03 caratère séparés par un espace: \n");
    scanf(" %c %c %c", &char1, &char2, &char3);
    printf("Vous avez entrer: %c, %c et %c\n", char1, char2, char3);

    return 0;
}

