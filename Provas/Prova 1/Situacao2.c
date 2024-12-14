#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10

typedef struct {
    char nome[50];
    int codigo;
    int quantidade;
} Produto;

void adicionarProduto(Produto estoque[], int *totalProdutos) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("\nO estoque está cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    printf("\nDigite o nome do produto: ");
    scanf("%[^]s", novoProduto.nome);
    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite a quantidade inicial em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    estoque[*totalProdutos] = novoProduto;
    (*totalProdutos)++;
    printf("\nProduto adicionado com sucesso!\n");
}

void atualizarQuantidade(Produto estoque[], int totalProdutos) {
    int codigo, novaQuantidade;
    printf("\nDigite o código do produto que deseja atualizar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado: %s\n", estoque[i].nome);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQuantidade);
            estoque[i].quantidade = novaQuantidade;
            printf("\nQuantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("\nProduto com o código %d não encontrado.\n", codigo);
}

void mostrarEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("\nO estoque está vazio.\n");
        return;
    }

    printf("\nEstoque atual:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto: %s | Código: %d | Quantidade: %d\n",
               estoque[i].nome, estoque[i].codigo, estoque[i].quantidade);
    }
}

int main() {
    Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1: Adicionar produto\n");
        printf("2: Atualizar quantidade\n");
        printf("3: Mostrar estoque atual\n");
        printf("4: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &totalProdutos);
                break;
            case 2:
                atualizarQuantidade(estoque, totalProdutos);
                break;
            case 3:
                mostrarEstoque(estoque, totalProdutos);
                break;
            case 4:
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
