#include <stdio.h>

int main(){
    int numeros[] = {1, 2, 3, 4, 5}, *ptr = numeros;

    for(int i=0; i<5; i++){
        printf("Elemento %d: %d\n", i , *(ptr+i));
    }

    return 0;
}