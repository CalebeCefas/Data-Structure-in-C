#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

void inicializar(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

int estaVazia(Fila *f) {
    return f->frente == -1;
}

int estaCheia(Fila *f) {
    return f->tras == MAX - 1;
}

void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    if (estaVazia(f)) {
        f->frente = 0;
    }
    f->itens[++f->tras] = valor;
}

int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int removido = f->itens[f->frente];
    if (f->frente >= f->tras) {
        inicializar(f);
    } else {
        f->frente++;
    }
    return removido;
}

int tamanhoFila(Fila *f) {
    if (estaVazia(f)) return 0;
    return f->tras - f->frente + 1;
}

int espacosVazios(Fila *f) {
    return MAX - tamanhoFila(f);
}

int fimFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->itens[f->tras];
}

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
    } while (opcao != 6);
    return 0;
}
