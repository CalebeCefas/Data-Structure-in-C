#include <stdlib.h>
#include <stdio.h>

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
    return;
}

int main(){
    int x, y;

    printf("Digite o valor de X: ");
    scanf("%d", &x);
    printf("Digite o valor de Y: ");
    scanf("%d", &y);

    troca(&x, &y);

    printf("Valor trocado de X: %d\nValor trocado de Y: %d", x, y);

    return 0;
}