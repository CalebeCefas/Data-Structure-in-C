#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef struct {
    int itens[TAMANHO], prioridade[TAMANHO], inicio, fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

int estaVazia(Fila *f) {
    return (f->inicio == -1);
}

int estaCheia(Fila *f) {
    return (f->fim == TAMANHO - 1);
}

void enfileirar(Fila *f, int valor, int prioridade) {
    if (estaCheia(f)) {
        printf("ERRO: Fila cheia\n");
        return;
    } else if (estaVazia(f)) {
        f->inicio = 0;
    }

    f->fim++;
    int i;
    for (i = f->fim - 1; i >= f->inicio && f->prioridade[i] < prioridade; i--) {
        f->itens[i + 1] = f->itens[i];
        f->prioridade[i + 1] = f->prioridade[i];
    }

    f->itens[i + 1] = valor;
    f->prioridade[i + 1] = prioridade;

    printf("Elemento %d com prioridade %d foi enfileirado!\n", valor, prioridade);
}

int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("ERRO: Fila vazia\n");
        return -1;
    }

    int valorRemovido = f->itens[f->inicio];

    if (f->inicio >= f->fim) {
        // Resetar fila
        inicializarFila(f);
    } else {
        f->inicio++;
    }

    return valorRemovido;
}

void exibirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    printf("\nElementos da fila (valor, prioridade): ");
    for (int i = f->inicio; i <= f->fim; i++) {
        printf("(%d, %d) ", f->itens[i], f->prioridade[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;

    inicializarFila(&fila);

    enfileirar(&fila, 10, 2);
    enfileirar(&fila, 20, 1);
    enfileirar(&fila, 40, 3);

    exibirFila(&fila);

    desenfileirar(&fila);

    exibirFila(&fila);

    return 0;
}