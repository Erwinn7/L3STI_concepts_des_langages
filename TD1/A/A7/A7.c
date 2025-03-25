/*
    Documentation section
    @Project A7 L3 
    @Author Meldi AHISSOU
    @Created 20221010
    @Program Description, Program to compute the area of a circle and encrypt/decrypt a word
*/

// Link section
#include <stdio.h>
#include <string.h>

// Definition section

// Global declaration section

// Function prototype declaration section
void intToRomanOld(int num, char *result);
void intToRomanModern(int num, char *result);

// Main function
int main(int argc, char const *argv[]){
    int number;
    char result[100];

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Convert using old notation
    result[0] = '\0'; // Initialize result string
    intToRomanOld(number, result);
    printf("Old Roman numeral: %s\n", result);

    // Convert using modern notation
    result[0] = '\0'; 
    intToRomanModern(number, result);
    printf("Modern Roman numeral: %s\n", result);

    return 0;
}

// Sub functions

// Function to convert integer to Roman numeral using old notation
void intToRomanOld(int num, char *result) {
    while (num >= 1000) { strcat(result, "M"); num -= 1000; }
    while (num >= 500) { strcat(result, "D"); num -= 500; }
    while (num >= 100) { strcat(result, "C"); num -= 100; }
    while (num >= 50) { strcat(result, "L"); num -= 50; }
    while (num >= 10) { strcat(result, "X"); num -= 10; }
    while (num >= 5) { strcat(result, "V"); num -= 5; }
    while (num >= 1) { strcat(result, "I"); num -= 1; }
}

// Function to convert integer to Roman numeral using modern notation
void intToRomanModern(int num, char *result) {
    while (num >= 1000) { strcat(result, "M"); num -= 1000; }
    if (num >= 900) { strcat(result, "CM"); num -= 900; }
    if (num >= 500) { strcat(result, "D"); num -= 500; }
    if (num >= 400) { strcat(result, "CD"); num -= 400; }
    while (num >= 100) { strcat(result, "C"); num -= 100; }
    if (num >= 90) { strcat(result, "XC"); num -= 90; }
    if (num >= 50) { strcat(result, "L"); num -= 50; }
    if (num >= 40) { strcat(result, "XL"); num -= 40; }
    while (num >= 10) { strcat(result, "X"); num -= 10; }
    if (num >= 9) { strcat(result, "IX"); num -= 9; }
    if (num >= 5) { strcat(result, "V"); num -= 5; }
    if (num >= 4) { strcat(result, "IV"); num -= 4; }
    while (num >= 1) { strcat(result, "I"); num -= 1; }
}

