#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void listarAlunos(Aluno *alunos, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha alunos cadastrados.\n");
    } else {
        printf("Lista de Alunos:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("Aluno %d:\n", i + 1);
            printf("  Nome: %s\n", alunos[i].nome);
            printf("  Idade: %d\n", alunos[i].idade);
            printf("  Nota: %.2f\n", alunos[i].nota);
        }
    }
}

void adicionarAluno(Aluno *alunos, int *tamanho) {
    if (*tamanho >= MAX) {
        printf("ERRO: limite de alunos atingido.\n");
        return;
    }

    Aluno novoAluno;
    printf("Digite o nome do aluno: ");
    getchar();
    fgets(novoAluno.nome, 50, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';

    printf("Digite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);

    printf("Digite a nota do aluno: ");
    scanf("%f", &novoAluno.nota);

    alunos[*tamanho] = novoAluno;
    (*tamanho)++;
    printf("Aluno adicionado com sucesso!\n");
}

void editarAluno(Aluno *alunos, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha alunos cadastrados para editar.\n");
        return;
    }

    listarAlunos(alunos, tamanho);

    int indice;
    printf("Digite o numero do aluno que deseja editar (1 a %d): ", tamanho);
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= tamanho) {
        printf("Indice invalido!\n");
        return;
    }

    printf("Editando o aluno %d:\n", indice + 1);
    printf("Digite o novo nome do aluno: ");
    getchar();
    fgets(alunos[indice].nome, 50, stdin);
    alunos[indice].nome[strcspn(alunos[indice].nome, "\n")] = '\0';

    printf("Digite a nova idade do aluno: ");
    scanf("%d", &alunos[indice].idade);

    printf("Digite a nova nota do aluno: ");
    scanf("%f", &alunos[indice].nota);

    printf("Aluno editado com sucesso!\n");
}

void removerAluno(Aluno *alunos, int *tamanho) {
    if (*tamanho == 0) {
        printf("Nao ha alunos cadastrados para remover.\n");
        return;
    }

    listarAlunos(alunos, *tamanho);

    int indice;
    printf("Digite o numero do aluno que deseja remover (1 a %d): ", *tamanho);
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= *tamanho) {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = indice; i < *tamanho - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*tamanho)--;
    printf("Aluno removido com sucesso!\n");
}


int main() {
    Aluno *alunos = (Aluno*)malloc(MAX * sizeof(Aluno));
    int tamanho = 0;
    int opcao;

    if (alunos == NULL) {
        printf("Erro ao alocar memoria para o array de alunos!\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Listar alunos\n");
        printf("2. Adicionar aluno\n");
        printf("3. Editar aluno\n");
        printf("4. Remover aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarAlunos(alunos, tamanho);
                break;
            case 2:
                adicionarAluno(alunos, &tamanho);
                break;
            case 3:
                editarAluno(alunos, tamanho);
                break;
            case 4:
                removerAluno(alunos, &tamanho);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    free(alunos);
    return 0;
}