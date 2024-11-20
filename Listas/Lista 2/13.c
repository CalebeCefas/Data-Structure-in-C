/*13.Alocação Dinâmica para Vetor de Inteiros:
Crie um programa que aloque dinamicamente um vetor de inteiros de
tamanho n, onde n é informado pelo usuário. Preencha o vetor com
valores informados pelo usuário e exiba os valores inseridos.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o dado %d de %d: ", i+1, n);
        scanf("%d", &array[i]);
    }

    printf("Array alocado dinamicamente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}