/*Soma dos Números até N:
Implemente uma função recursiva que calcule a soma de todos os
números naturais até um valor N fornecido pelo usuário. Exemplo: para N
= 5, o resultado deve ser 15 (1 + 2 + 3 + 4 + 5).*/

#include <stdio.h>

int soma(int n){
    if(n<=0){
        return 0;
    }

    return n + soma(n-1);
}

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("Soma de 1 a %d: %d", n, soma(n));

    return 0;
}