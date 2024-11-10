#include <stdio.h>
#include <stdlib.h>
struct Estudante {
    char nome[50];
    int idade;
    float media;
};

int main() {
    // Aloca dinamicamente memória para um estudante
    struct Estudante *aluno = (struct Estudante *)malloc(sizeof(struct Estudante));

    // Verifica se a alocação foi bem-sucedida
    if (aluno == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Recebe valores para os campos da struct
    printf("Digite o nome do estudante: ");
    scanf("%s", aluno->nome);
    printf("Digite a idade: ");
    scanf("%d", &aluno->idade);
    printf("Digite a média: ");
    scanf("%f", &aluno->media);

    // Exibe os valores inseridos
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Média: %.2f\n", aluno->media);

    free(aluno);  // Libera a memória alocada
    return 0;

}

