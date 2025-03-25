/*
    Documentation section
    @Project TD1 A1 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to sum a list of number 
*/ 

//Link section
#include <stdio.h>
#include <stdlib.h>

//Main function
int main(int argc, char const *argv[])
{
    if (argc < 3){
        printf("Wrong usage, at least 2 parameters expected:\n ./sum param1 param2 ");
        return 1;
    }
    
    int sum = 0;
    for (int i = 1; i < argc; i++) {

        int num = atoi(argv[i]);
        if (num == 0 && (*argv[i] != '0')) {
            printf("There is a problem with args %d: %s. It could not be transformed in int. Please retry !", i, argv[i]);
            return -1;
        }

        sum += num;
    }
    printf("La somme des arguments est: %d\n", sum);

    return 0;
}



