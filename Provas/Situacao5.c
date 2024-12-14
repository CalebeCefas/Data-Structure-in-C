#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
    char nome[50];
    int totalAulas;
    int presencas;
} Aluno;

void registrarPresenca(Aluno alunos[], int totalAlunos) {
    char nome[50];
    printf("\nDigite o nome do aluno para registrar a presença: ");
    scanf(" %[^]s", nome);

    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            alunos[i].presencas++;
            alunos[i].totalAulas++;
            printf("Presença registrada para o aluno %s.\n", alunos[i].nome);
            return;
        }
    }
    printf("Aluno não encontrado. Certifique-se de que o nome está correto.\n");
}

void consultarFrequencia(Aluno alunos[], int totalAlunos) {
    printf("\nFrequência dos alunos:\n");
    for (int i = 0; i < totalAlunos; i++) {
        float porcentagem = (alunos[i].totalAulas > 0) ? 
                            ((float)alunos[i].presencas / alunos[i].totalAulas) * 100 : 0;
        printf("Aluno: %s | Presenças: %d | Total de Aulas: %d | Frequência: %.2f%%\n",
               alunos[i].nome, alunos[i].presencas, alunos[i].totalAulas, porcentagem);
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0, opcao;

    printf("Quantos alunos há na turma? (Max %d): ", MAX_ALUNOS);
    scanf("%d", &totalAlunos);

    for (int i = 0; i < totalAlunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^]s", alunos[i].nome);
        alunos[i].totalAulas = 0;
        alunos[i].presencas = 0;
    }

    do {
        printf("\nMenu:\n");
        printf("1: Registrar presença\n");
        printf("2: Consultar frequência\n");
        printf("3: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarPresenca(alunos, totalAlunos);
                break;
            case 2:
                consultarFrequencia(alunos, totalAlunos);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
