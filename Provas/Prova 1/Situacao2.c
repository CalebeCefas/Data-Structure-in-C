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
        printf("\nO estoque esta cheio. Nao eh possivel adicionar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite a quantidade inicial em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    estoque[*totalProdutos] = novoProduto;
    (*totalProdutos)++;
    printf("\nProduto adicionado com sucesso!\n");
}

void atualizarQuantidade(Produto estoque[], int totalProdutos) {
    int codigo, novaQuantidade;
    printf("\nDigite o codigo do produto que deseja atualizar: ");
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
    printf("\nProduto com o codigo %d nao encontrado.\n", codigo);
}

void mostrarEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("\nO estoque esta vazio.\n");
        return;
    }

    printf("\nEstoque atual:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto: %s | Codigo: %d | Quantidade: %d\n",
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
        printf("Escolha uma opcao: ");
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
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
