#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Estrutura da fila com um vetor e dois índices (frente e trás)
typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

// Inicializa a fila, definindo os índices como -1 (fila vazia)
void inicializar(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->frente == -1;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return f->tras == MAX - 1;
}

// Adiciona um elemento no final da fila
void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    if (estaVazia(f)) {
        f->frente = 0; // Define a frente ao adicionar o primeiro elemento
    }
    f->itens[++f->tras] = valor;
}

// Remove um elemento do início da fila
int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int removido = f->itens[f->frente];
    if (f->frente >= f->tras) {
        inicializar(f); // Reseta a fila se o último elemento for removido
    } else {
        f->frente++;
    }
    return removido;
}

// Retorna o número de elementos atualmente na fila
int tamanhoFila(Fila *f) {
    if (estaVazia(f)) return 0;
    return f->tras - f->frente + 1;
}

// Retorna a quantidade de espaços ainda disponíveis na fila
int espacosVazios(Fila *f) {
    return MAX - tamanhoFila(f);
}

// Retorna o último elemento da fila sem removê-lo
int fimFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->itens[f->tras];
}

// Exibe todos os elementos da fila
void exibirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializar(&fila);
    int opcao, valor;
    do {
        // Menu de opções para o usuário interagir com a fila
        printf("\n1. Enfileirar\n2. Desenfileirar\n3. Exibir Fila\n4. Tamanho da Fila\n5. Último Elemento\n6. Sair\nEscolha: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                printf("Elemento removido: %d\n", desenfileirar(&fila));
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 4:
                printf("Tamanho da fila: %d\n", tamanhoFila(&fila));
                printf("Espaços vazios: %d\n", espacosVazios(&fila));
                break;
            case 5:
                printf("Último elemento: %d\n", fimFila(&fila));
                break;
        }
    } while (opcao != 6); // Sai do loop quando o usuário escolher a opção 6
    return 0;
}
