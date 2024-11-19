/*9. Cadastro de Alunos com Structs:
Defina um struct para armazenar informações de um aluno (nome, idade
e média de notas). Em seguida, crie uma função que receba uma lista de
alunos e exiba os dados de cada um.*/

#include <stdio.h>

struct Aluno {
    char nome[100];
    int idade;
    float media;
};

int main() {
    struct Aluno alunos[50];
    int n;

    printf("Quantos alunos serao cadastrados (1 a 50): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Digite a media: ");
        scanf("%f", &alunos[i].media);
    }

    printf("\nDados dos alunos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Media: %.2f\n", alunos[i].media);
    }

    return 0;
}
