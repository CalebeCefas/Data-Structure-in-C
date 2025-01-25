#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef struct {
    int itens[TAMANHO], inicio, fim;
} Fila;

void inicializarFila (Fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

int estaVazia (Fila *f) {
    return (f->inicio == -1);
}

int estaCheia (Fila *f) {
    return (f->fim == TAMANHO -1);
}

void enfileirar (Fila *f, int valor) {
    if(estaCheia(f)) {
        printf("ERRO: Fila cheia");
    } else if (estaVazia(f)) {
        f->inicio = 0;
    }

    f->fim++;
    f->itens[f->fim] = valor;
    printf("Elemento %d foi enfileirado!\n", valor);
}

int desenfileirar(Fila *f){
    if (estaVazia(f)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    int valorRemovido = f->itens[f->inicio];

    if (f->inicio >= f->fim) {
        //Resetar fila
        inicializarFila(f);
        printf("Fila reinicializada");
    } else {
        f-> inicio++;
    }

    return valorRemovido;
}

void exibirFila (Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia");
        return;
    }

    printf("Elementos da fila: ");
    for(int i = f->inicio; i <= f->fim; i++){
        printf("%d ", f->itens[i]);
    }
}

int main () {
    Fila fila;

    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 40);

    exibirFila(&fila);

    desenfileirar(&fila);

    exibirFila(&fila);
}