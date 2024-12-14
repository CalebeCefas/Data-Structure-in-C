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

void converterParaBinario(int numero) {
    Pilha pilha;
    inicializarPilha(&pilha);

    while (numero > 0) {
        empilhar(&pilha, numero % 2);
        numero /= 2;
    }

    printf("Número binário: ");
    while (!pilhaVazia(&pilha)) {
        printf("%d", desempilhar(&pilha));
    }
    printf("\n");
}

int main() {
    int numero;

    printf("Digite um número inteiro positivo para converter em binário: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: número inválido. Apenas inteiros positivos são permitidos.\n");
        return 1;
    }

    converterParaBinario(numero);

    return 0;
}
