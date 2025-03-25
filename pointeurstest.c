/*
    Documentation section
    @Project TD1 A1 L3 
    @Author Meldi AHISSOU 
    @Created 20221010
    @Program Description, Program to compute the area of a cirlce
*/


#include <stdio.h>
#include <stdlib.h>


// void swap_int (int* ptr_a , int* ptr_b){
//     int c = *ptr_a;
//     *ptr_a = *ptr_b;
//     *ptr_b = c ;
// }



int main(int argc, char const *argv[]){
 
    int a=10, b=20;
    printf("a=%d et b=%d \n",a,b);
    if (sizeof(a) == sizeof(b)){
        swap_int(&a,&b);
    }
    printf("a=%d et b=%d \n",a,b);


}

