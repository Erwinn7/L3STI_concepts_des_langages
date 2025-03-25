/*
    Documentation section
    @Project TD1 B3 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to dynamically allocate memory for a char, an int, and a float, initialize them with user input, display the values, and repeat or exit based on user input.
*/ 

//Link section
#include <stdio.h>
#include <stdlib.h>

//Main function
int main(int argc, char const *argv[])
{
    char *charPtr;
    int *intPtr;
    float *floatPtr;
    char choice;

    do {
        // Allocate memory
        charPtr = (char *)malloc(sizeof(char));
        intPtr = (int *)malloc(sizeof(int));
        floatPtr = (float *)malloc(sizeof(float));

        if (charPtr == NULL || intPtr == NULL || floatPtr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Get user input
        printf("Enter a caratère: ");
        scanf(" %c", charPtr);
        printf("Enter un entier: ");
        scanf("%d", intPtr);
        printf("Enter un nombre à virgule: ");
        scanf("%f", floatPtr);

        // Display values
        printf("vous avez entrer: %c, %d, %f\n", *charPtr, *intPtr, *floatPtr);

        // Free allocated memory
        free(charPtr);
        free(intPtr);
        free(floatPtr);

        // Ask user if they want to continue
        printf("Voulez vous continuer? (o/n): ");
        scanf(" %c", &choice);

    } while (choice == 'o' || choice == 'O');

    return 0;
}
