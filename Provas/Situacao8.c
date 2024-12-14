#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}

void exibirPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Elementos na pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int arrayRetirados[MAX], countRetirados = 0;
    int opcao, valor;

    do {
        printf("\nMenu de Operações com Pilha\n");
        printf("1: Inserir dados na pilha\n");
        printf("2: Retirar dados da pilha\n");
        printf("3: Verificar se a pilha está cheia\n");
        printf("4: Verificar se a pilha está vazia\n");
        printf("5: Mostrar pilha e array auxiliar\n");
        printf("6: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                break;

            case 2:
                valor = desempilhar(&pilha);
                if (valor != -1) {
                    printf("Valor retirado: %d\n", valor);
                    arrayRetirados[countRetirados++] = valor;
                }
                break;

            case 3:
                if (pilhaCheia(&pilha)) {
                    printf("A pilha está cheia.\n");
                } else {
                    printf("A pilha não está cheia.\n");
                }
                break;

            case 4:
                if (pilhaVazia(&pilha)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;

            case 5:
                printf("\nEstado da pilha:\n");
                exibirPilha(&pilha);

                printf("\nValores retirados (array auxiliar):\n");
                if (countRetirados == 0) {
                    printf("Nenhum valor retirado ainda.\n");
                } else {
                    for (int i = 0; i < countRetirados; i++) {
                        printf("%d ", arrayRetirados[i]);
                    }
                    printf("\n");
                }
                break;

            case 6:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}
