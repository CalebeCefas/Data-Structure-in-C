#include <stdio.h>

int valorMaior(int *array, int t, int i, int maior) {
    if (i == t) {
        return maior;
    }

    if (array[i] > maior) {
        maior = array[i];
    }

    return valorMaior(array, t, i + 1, maior);
}

int main() {
    int t, Maior, maior = -100000000, i;

    printf("Digite o tamanho do array: ");
    scanf("%d", &t);

    int array[t];
    for (i = 0; i < t; i++) {
        printf("Digite o valor %d de %d: ", i + 1, t);
        scanf("%d", &array[i]);
    }

    Maior = valorMaior(array, t, 0, maior);

    printf("O maior valor digitado foi: %d\n", Maior);

    return 0;
}
