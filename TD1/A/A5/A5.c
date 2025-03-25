/*
    Documentation section
    @Project A5 L3 
    @Author Meldi AHISSOU
    @Created 20221010
    @Program Description, macro pscanf testing
*/

//Link section
#include <stdio.h>

//Definition section
#define pscanf(message, format, var) \
    do { \
        printf(message); \
        scanf(format, var); \
    } while(0)


//Main function
int main(int argc, char const *argv[])
{
    int number;
    pscanf("Enter un nombre: ", "%d", &number);
    printf("Vous avez entrez: %d\n", number);

    return 0;
}


