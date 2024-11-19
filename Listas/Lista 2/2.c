/*2. Cálculo de Fatorial:
Escreva uma função recursiva que calcule o fatorial de um número N.
Utilize o caso base N = 0, que deve retornar 1, e o caso recursivo que
multiplica N pelo fatorial de N - 1.*/

#include <stdio.h>

int fatorial(int n){
    if(n<=1){
        return 1;
    }

    return n*fatorial(n-1);
}

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("Fatorial de %d: %d", n, fatorial(n));

    return 0;
}