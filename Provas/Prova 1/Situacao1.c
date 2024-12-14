#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[100];
    int matricula;
    char curso[100];
} Aluno;

void adicionarAluno(Aluno *alunos, int *tamanho) {
    if (*tamanho >= 5) {
        printf("ERRO: limite de alunos atingido.\n");
        return;
    }

    Aluno novoAluno;
    printf("Digite o nome do aluno: ");
    getchar();
    fgets(novoAluno.nome, 100, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';

    printf("Digite a matricula do aluno: ");
    scanf("%d", &novoAluno.matricula);

    printf("Digite o curso do aluno: ");
    getchar();
    fgets(novoAluno.curso, 100, stdin);
    novoAluno.curso[strcspn(novoAluno.curso, "\n")] = '\0';

    alunos[*tamanho] = novoAluno;
    (*tamanho)++;
    printf("Aluno adicionado com sucesso!\n");
}

void listarAlunos(Aluno *alunos, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha alunos cadastrados.\n");
    } else {
        printf("Lista de Alunos:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("Aluno %d:\n", i + 1);
            printf("  Nome: %s\n", alunos[i].nome);
            printf("  Matricula: %d\n", alunos[i].matricula);
            printf("  Curso: %s\n", alunos[i].curso);
        }
    }
}

int main() {
    Aluno *alunos = (Aluno*)malloc(5 * sizeof(Aluno));
    int tamanho = 0;
    int opcao;

    if (alunos == NULL) {
        printf("Erro ao alocar memória para o array de alunos!\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar alunos\n");
        printf("2. Listar aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, &tamanho);
                break;
            case 2:
                listarAlunos(alunos, tamanho);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    free(alunos);
    return 0;
}