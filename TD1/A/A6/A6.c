/*
    Documentation section
    @Project A6 L3 
    @Author Meldi AHISSOU
    @Created 20221010
    @Program Description, Program to compute the area of a circle and encrypt/decrypt a word
*/

//Link section
#include <stdio.h>
#include <string.h>

//Definition section

//Global declaration section

//Function prototype declaration section
void chiffrer(char* mot, int cle);
void dechiffrer(char* mot, int cle);

//Main function
int main(int argc, char const *argv[])
{
    char mot[100];
    int cle;

    printf("Entrez la clé de chiffrement: ");
    scanf("%d", &cle);

    printf("Entrez le mot à chiffrer: ");
    scanf("%s", mot);

    chiffrer(mot, cle);
    printf("Mot chiffré: %s\n", mot);

    dechiffrer(mot, cle);
    printf("Mot déchiffré: %s\n", mot);

    return 0;
}

//Sub functions
void chiffrer(char* mot, int cle) {
    for (int i = 0; i < strlen(mot); i++) {
        mot[i] = mot[i] + cle;
    }
}

void dechiffrer(char* mot, int cle) {
    for (int i = 0; i < strlen(mot); i++) {
        mot[i] = mot[i] - cle;
    }
}
