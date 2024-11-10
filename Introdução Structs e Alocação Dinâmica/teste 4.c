#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[50];
    int idade;
    float media;
};

int main() {
    int numAlunos;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &numAlunos);

    // Alocando memória para um array de structs Aluno
    struct Aluno *alunos = (struct Aluno *) malloc(numAlunos * sizeof(struct Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Retorna erro
    }

    // Entrada de dados para cada aluno
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome); // Lê uma string com espaços
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);
        printf("Digite a media do aluno: ");
        scanf("%f", &alunos[i].media);
    }

    // Exibindo os dados dos alunos
    printf("\n--- Dados dos Alunos ---\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Media: %.2f\n\n", alunos[i].media);
    }

    // Liberando a memória alocada
    free(alunos);

    return 0;
}
