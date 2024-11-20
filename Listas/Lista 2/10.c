/*10.Manipulação de Dados de um Produto:
Crie um struct para representar um produto com os campos nome, preço
e quantidade. Em seguida, escreva uma função que atualize a quantidade
de um produto e exiba o valor total em estoque.*/

#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

float atualizarProduto(struct Produto *produtos) {
    char busca[100];
    printf("Qual produto sera atualizado?: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < 100; i++) {
        if (strcmp(busca, produtos[i].nome) == 0) {
            printf("Produto encontrado: %s\n", produtos[i].nome);

            printf("Qual sera o novo preco?: ");
            scanf("%f", &produtos[i].preco);

            printf("Qual sera a nova quantidade?: ");
            scanf("%d", &produtos[i].quantidade);

            return produtos[i].preco * produtos[i].quantidade;
        }
    }

    printf("Produto nao encontrado!\n");
    return -1;
}

int main() {
    struct Produto produtos[10] = {
        {"Arroz", 5.50, 30},
        {"Feijao", 7.30, 20},
        {"Macarrao", 4.20, 50},
        {"Oleo", 8.90, 15},
        {"Acucar", 3.10, 40},
        {"Sal", 2.00, 100},
        {"Leite", 6.50, 25},
        {"Cafe", 15.00, 10},
        {"Farinha", 4.50, 35},
        {"Bolacha", 2.80, 60}
    };

    char op;
    printf("Deseja atualizar algum produto? (s/n): ");
    scanf(" %c", &op);

    if (op == 's' || op == 'S') {
        float total = atualizarProduto(produtos);

        if (total != -1) {
            printf("Novo valor total em estoque: R$ %.2f\n", total);
        }
    } else {
        printf("Ate mais!!!\n");
    }

    return 0;
}