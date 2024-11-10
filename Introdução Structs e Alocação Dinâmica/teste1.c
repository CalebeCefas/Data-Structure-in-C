#include<stdio.h>

struct Estudante{
char nome[50];
int idade;
float media;
};

int main(){
struct Estudante aluno1;
    printf("Digite a idade do estudante: ");
    scanf("%d", &aluno1.idade);
    printf("Digite a media do estudante: ");
    scanf("%f", &aluno1.media);
    snprintf(aluno1.nome, sizeof(aluno1.nome), "Maria");
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Media: %.2f\n", aluno1.media);
   
return 0;

}