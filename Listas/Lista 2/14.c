/*14.Cadastro Dinâmico de Alunos:
Escreva um programa que utilize alocação dinâmica para cadastrar uma
lista de alunos, onde o número de alunos é informado pelo usuário. Utilize
malloc para alocar memória para cada aluno, armazenando nome e idade.*/

#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[100];
    int idade;
};

int main() {
    int numAlunos;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &numAlunos);

    struct Aluno *alunos = (struct Aluno *) malloc(numAlunos * sizeof(struct Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);
    }

    printf("\n--- Dados dos Alunos ---\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
    }

    free(alunos);

    return 0;
}
