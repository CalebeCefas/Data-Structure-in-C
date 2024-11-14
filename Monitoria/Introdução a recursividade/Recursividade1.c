#include <stdio.h>
#include <stdlib.h>

int somaImpar(int *array, int t) {
    if (t == 0) {
        return 0;
    }

    if (array[t - 1] % 2 == 1) {
        return array[t - 1] + somaImpar(array, t - 1);
    } else {
        return somaImpar(array, t - 1);
    }
}

int main(){
    int t, sum;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);

    int array[t];
    for(int i = 0; i<t; i++){
        printf("Digite o o dado %d de %d: ", i+1, t);
        scanf("%d", &array[i]);
        printf("\n");
    }

    sum = somaImpar(array, t);
    printf("\nSoma dos dados impares do vetor: %d", sum);
    return 0;
}