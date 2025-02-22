#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Estrutura de um item da fila, contendo valor e prioridade
typedef struct {
    int valor;
    int prioridade;
} Item;

// Estrutura da fila de prioridade, contendo um vetor de itens e variáveis auxiliares
typedef struct {
    Item itens[MAX]; // Vetor que armazena os elementos da fila
    int tamanho; // Número atual de elementos na fila
    int semPrioridade; // Contador de elementos sem prioridade informada
} FilaPrioridade;

// Inicializa a fila, definindo tamanho e contador de elementos sem prioridade
void inicializar(FilaPrioridade *fp) {
    fp->tamanho = 0;
    fp->semPrioridade = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaPrioridade *fp) {
    return fp->tamanho == 0;
}

// Verifica se a fila está cheia
int estaCheia(FilaPrioridade *fp) {
    return fp->tamanho == MAX;
}

// Insere um elemento na fila de prioridade
void enfileirar(FilaPrioridade *fp, int valor, int prioridade) {
    if (estaCheia(fp)) {
        printf("Fila cheia!\n");
        return;
    }
    // Se o usuário não informar prioridade (-1), será 0 (menor prioridade)
    if (prioridade == -1) {
        if (fp->semPrioridade >= 5) { // Bloqueia a entrada do sexto elemento sem prioridade
            printf("Nao é permitido inserir mais elementos sem prioridade.\n");
            return;
        }
        prioridade = 0;
        fp->semPrioridade++;
    }
    
    // Inserção ordenada por prioridade (do maior para o menor)
    int i = fp->tamanho - 1;
    while (i >= 0 && fp->itens[i].prioridade < prioridade) {
        fp->itens[i + 1] = fp->itens[i];
        i--;
    }
    // Insere o novo elemento na posição correta
    fp->itens[i + 1].valor = valor;
    fp->itens[i + 1].prioridade = prioridade;
    fp->tamanho++;
}

// Exibe os elementos da fila, permitindo exibição total ou de uma posição específica
void exibirFila(FilaPrioridade *fp) {
    int opcao;
    printf("Digite 1 para exibir toda a fila ou 2 para exibir uma posicao específica: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        // Exibe todos os elementos da fila
        for (int i = 0; i < fp->tamanho; i++) {
            printf("Valor: %d, Prioridade: %d\n", fp->itens[i].valor, fp->itens[i].prioridade);
        }
    } else if (opcao == 2) {
        int pos;
        printf("Digite a posicao desejada: ");
        scanf("%d", &pos);
        if (pos >= 0 && pos < fp->tamanho) {
            // Exibe apenas a posição escolhida
            printf("Valor: %d, Prioridade: %d\n", fp->itens[pos].valor, fp->itens[pos].prioridade);
        } else {
            printf("Posicao inválida!\n");
        }
    }
}

// Retorna o número de elementos na fila
int tamanhoFila(FilaPrioridade *fp) {
    return fp->tamanho;
}

// Retorna quantos espaços ainda estão disponíveis na fila
int espacosVazios(FilaPrioridade *fp) {
    return MAX - fp->tamanho;
}

int main() {
    FilaPrioridade fp;
    inicializar(&fp);
    
    // Testando inserções na fila
    enfileirar(&fp, 10, -1); // Sem prioridade
    enfileirar(&fp, 20, 2);  // Com prioridade 2
    enfileirar(&fp, 30, -1); // Sem prioridade
    
    // Exibe os elementos da fila
    exibirFila(&fp);
    
    // Exibe informações sobre a fila
    printf("Tamanho da fila: %d\n", tamanhoFila(&fp));
    printf("Espacos vazios: %d\n", espacosVazios(&fp));
    
    return 0;
}
