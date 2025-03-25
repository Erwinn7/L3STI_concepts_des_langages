/*
    Documentation section
    @Project TD1 B2 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to sum a list of number 
*/ 

//Link section
#include <stdio.h>
#include <stdlib.h>

//Function prototype declaration section
void add(int a, int b, int *c);
//Main function
int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 10;
    int c;

    add(a, b, &c);

    printf("La somme de %d et %d est: %d\n", a, b, c);

    return 0;
}

// Function to add two numbers and store the result in the third parameter
void add(int a, int b, int *c) {
    *c = a + b;
}