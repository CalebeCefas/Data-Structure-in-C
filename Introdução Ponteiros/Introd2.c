#include <stdio.h>

void dobrar(int *num){
    *num = *num * 2;
}

int main(){
    int valor = 15;
    printf("Valor antes: %d\n", valor);
    
    dobrar(&valor);
    printf("Valor depois: %d\n", valor);

    return 0;
}