#include <stdlib.h>
#include <stdio.h>

int main(){
    int valor = 20;
    int *ptr = &valor;
    
    printf("Valor inicial: %d\n", valor);
    
    *ptr = 30;
    printf("Valor modificado: %d\n", valor);

    return 0;
}