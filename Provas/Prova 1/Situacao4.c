#include <stdio.h>

unsigned long long calcularFatorial(int numero) {
    unsigned long long fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    int numero;

    printf("Gerador de Fatoriais\n");

    do {
        printf("\nDigite um numero inteiro positivo: ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("Entrada invalida! Apenas numeros inteiros positivos sao aceitos.\n");
        }
    } while (numero < 0);

    unsigned long long resultado = calcularFatorial(numero);
    printf("O fatorial de %d eh: %llu\n", numero, resultado);

    return 0;
}
