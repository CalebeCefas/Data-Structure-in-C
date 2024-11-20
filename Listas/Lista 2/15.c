/*15.Cálculo de Média com Alocação Dinâmica:
Implemente um programa que aloque dinamicamente um vetor de notas
de uma turma. O programa deve calcular a média das notas e liberar a
memória ao final. O número de notas é informado pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float total = 0, media;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade de notas inválida.\n");
        return 1;
    }

    float *notas = (float *) malloc(n * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite a nota %d de %d: ", i + 1, n);
        scanf("%f", &notas[i]);
        total += notas[i];
    }

    media = total / n;
    printf("Média das notas: %.2f\n", media);

    free(notas);

    return 0;
}
