/*12.Uso de Ponteiros com Structs:
Crie um programa que use um struct para representar as informações de
um funcionário (nome, idade e salário). Em seguida, escreva uma função
que receba um ponteiro para esse struct e aumente o salário em 10%.*/

#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[100];
    int idade;
    float salario;
};

void aumentarSalario(struct Funcionario *funcionario) {
    printf("\nFuncionario: %s\n", funcionario->nome);
    printf("Salario antigo: %.2f\n", funcionario->salario);

    funcionario->salario += funcionario->salario * 0.1;

    printf("Salario atualizado: %.2f\n", funcionario->salario);
}

int main() {
    struct Funcionario funcionario = {"Carlos Silva", 45, 3500.50};

    printf("Informaçoes do funcionario antes do aumento:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Salario: %.2f\n", funcionario.salario);

    aumentarSalario(&funcionario);

    printf("\nInformacoes do funcionario apos o aumento:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Salario: %.2f\n", funcionario.salario);

    return 0;
}