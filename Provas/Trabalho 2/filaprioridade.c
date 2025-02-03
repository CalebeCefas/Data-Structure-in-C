#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int valor;
    int prioridade;
} Item;

typedef struct {
    Item itens[MAX];
    int tamanho;
    int semPrioridade;
} FilaPrioridade;

void inicializar(FilaPrioridade *fp) {
    fp->tamanho = 0;
    fp->semPrioridade = 0;
}

int estaVazia(FilaPrioridade *fp) {
    return fp->tamanho == 0;
}

int estaCheia(FilaPrioridade *fp) {
    return fp->tamanho == MAX;
}

void enfileirar(FilaPrioridade *fp, int valor, int prioridade) {
    if (estaCheia(fp)) {
        printf("Fila cheia!\n");
        return;
    }
    if (prioridade == -1) {
        if (fp->semPrioridade >= 5) {
            printf("Nao é permitido inserir mais elementos sem prioridade.\n");
            return;
        }
        prioridade = 0;
        fp->semPrioridade++;
    }
    int i = fp->tamanho - 1;
    while (i >= 0 && fp->itens[i].prioridade < prioridade) {
        fp->itens[i + 1] = fp->itens[i];
        i--;
    }
    fp->itens[i + 1].valor = valor;
    fp->itens[i + 1].prioridade = prioridade;
    fp->tamanho++;
}

void exibirFila(FilaPrioridade *fp) {
    int opcao;
    printf("Digite 1 para exibir toda a fila ou 2 para exibir uma posicao específica: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        for (int i = 0; i < fp->tamanho; i++) {
            printf("Valor: %d, Prioridade: %d\n", fp->itens[i].valor, fp->itens[i].prioridade);
        }
    } else if (opcao == 2) {
        int pos;
        printf("Digite a posicao desejada: ");
        scanf("%d", &pos);
        if (pos >= 0 && pos < fp->tamanho) {
            printf("Valor: %d, Prioridade: %d\n", fp->itens[pos].valor, fp->itens[pos].prioridade);
        } else {
            printf("Posicao inválida!\n");
        }
    }
}

int tamanhoFila(FilaPrioridade *fp) {
    return fp->tamanho;
}

int espacosVazios(FilaPrioridade *fp) {
    return MAX - fp->tamanho;
}

int main() {
    FilaPrioridade fp;
    inicializar(&fp);
    enfileirar(&fp, 10, -1);
    enfileirar(&fp, 20, 2);
    enfileirar(&fp, 30, -1);
    exibirFila(&fp);
    printf("Tamanho da fila: %d\n", tamanhoFila(&fp));
    printf("Espacos vazios: %d\n", espacosVazios(&fp));
    return 0;
}
