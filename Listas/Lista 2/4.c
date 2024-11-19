/*4. Potência de um Número:
Crie uma função recursiva que calcule a potência de um número, dados
a base e o expoente. Por exemplo, 2^3 = 8. Use expoente = 0 como caso
base, que deve retornar 1.*/

#include <stdio.h>

int potencia(int n, int x){
    if(x<=0){
        return 1;
    }

    return n*potencia(n,x-1);
}

int main(){
    int n, x;
    printf("Digite um valor: ");
    scanf("%d", &n);
    printf("Qual sera a potencia desse valor: ");
    scanf("%d", &x);

    printf("Valor de %d^%d: %d", n, x, potencia(n,x));

    return 0;
}