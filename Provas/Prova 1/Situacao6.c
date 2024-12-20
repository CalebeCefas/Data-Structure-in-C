#include <stdio.h>
#include <stdlib.h>

float* inserirNotas(int *quantidade) {
    printf("Digite a quantidade de notas: ");
    scanf("%d", quantidade);

    if (*quantidade <= 0) {
        printf("Quantidade de notas invalida.\n");
        return NULL;
    }

    float *notas = (float *)malloc((*quantidade) * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < *quantidade; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    return notas;
}

float calcularMedia(float *notas, int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += notas[i];
    }
    return soma / quantidade;
}

void exibirNotas(float *notas, int quantidade) {
    printf("\nNotas armazenadas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nota %d: %.2f\n", i + 1, notas[i]);
    }
}

int main() {
    int opcao, quantidade = 0;
    float *notas = NULL;

    do {
        printf("\nGerenciador de Notas\n");
        printf("1: Inserir notas\n");
        printf("2: Calcular media\n");
        printf("3: Exibir notas\n");
        printf("4: Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (notas != NULL) {
                    free(notas);
                }
                notas = inserirNotas(&quantidade);
                break;

            case 2:
                if (notas == NULL || quantidade == 0) {
                    printf("Nenhuma nota inserida ainda.\n");
                } else {
                    float media = calcularMedia(notas, quantidade);
                    printf("Media das notas: %.2f\n", media);
                }
                break;

            case 3:
                if (notas == NULL || quantidade == 0) {
                    printf("Nenhuma nota inserida ainda.\n");
                } else {
                    exibirNotas(notas, quantidade);
                }
                break;

            case 4:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opçao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    if (notas != NULL) {
        free(notas);
    }

    return 0;
}
