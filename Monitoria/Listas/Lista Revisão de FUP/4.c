#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idade;
    int anoNascimento;
    int anoAtual;
} Idade;

Idade* criar(int idade, int anoN, int anoA) {
    Idade *pessoa = (Idade*)malloc(sizeof(Idade));
    if (pessoa != NULL) {
        pessoa->idade = idade;
        pessoa->anoNascimento = anoN;
        pessoa->anoAtual = anoA;
    }
    return pessoa;
}

int calcular(Idade *pessoa) {
    if (pessoa == NULL) {
        return -1;
    }
    return (pessoa->idade == pessoa->anoAtual - pessoa->anoNascimento) ? 1 : 0;
}

void libera(Idade *pessoa) {
    free(pessoa);
}

int main() {
    int idade, anoNascimento, anoAtual;

    printf("Digite a idade: ");
    scanf("%d", &idade);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &anoNascimento);
    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    Idade *pessoa = criar(idade, anoNascimento, anoAtual);
    if (pessoa == NULL) {
        printf("Erro ao alocar memoria para a struct.\n");
        return 1;
    }

    int fezAniversario = calcular(pessoa);
    if (fezAniversario == 1) {
        printf("A pessoa ja fez aniversario esse ano.\n");
    } else if (fezAniversario == 0) {
        printf("A pessoa ainda nao fez aniversario esse ano.\n");
    } else {
        printf("Erro ao calcular o aniversario.\n");
    }

    libera(pessoa);
    return 0;
}
