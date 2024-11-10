/*Escreva um algoritmo em linguagem C que utilize uma função para trocar o valor de duas
variáveis inteiras x e y, e exiba o valor de x e y após a troca. Explique o porquê você
usou passagem por referência ou passagem por valor.

OBS: As variáveis devem ser criadas na int main, trocadas pela função e exibidas na int
main.*/

#include <stdio.h>
#include <stdlib.h>

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

    printf("Novo valor de X: %d\n", x);
    printf("Novo valor de Y: %d\n", y);

    return 0;
}