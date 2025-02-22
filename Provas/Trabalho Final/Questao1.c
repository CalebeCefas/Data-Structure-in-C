#include <stdio.h>

#define MAX 10 // Definindo o tamanho máximo da lista

// Estrutura para a lista estática
typedef struct {
    int elementos[MAX]; // Vetor para armazenar os numeros
    int tamanho; // Controla a quantidade de elementos na lista
} Lista;

// Funcao para inicializar a lista, definindo o tamanho como 0
void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

// Funcao para inserir um numero na lista
void inserirNumero(Lista *lista, int num) {
    if (lista->tamanho < MAX) { // Verifica se há espaço disponível na lista
        lista->elementos[lista->tamanho] = num; // Insere o numero na próxima posicao disponível
        lista->tamanho++; // Incrementa o tamanho da lista
        printf("Numero %d inserido com sucesso!\n", num);
    } else {
        printf("Erro: a lista está cheia!\n"); // Mensagem de erro se a lista estiver cheia
    }
}

// Funcao para remover um numero da lista
void removerNumero(Lista *lista, int num) {
    int i, j;
    for (i = 0; i < lista->tamanho; i++) { // Percorre a lista para encontrar o numero
        if (lista->elementos[i] == num) { // Se encontrar o numero
            // Desloca os elementos subsequentes para a esquerda para preencher o espaço vazio
            for (j = i; j < lista->tamanho - 1; j++) {
                lista->elementos[j] = lista->elementos[j + 1];
            }
            lista->tamanho--; // Diminui o tamanho da lista após a remocao
            printf("Numero %d removido com sucesso!\n", num);
            return;
        }
    }
    printf("Erro: numero %d não encontrado na lista!\n", num); // Mensagem de erro se o numero não for encontrado
}

// Funcao para buscar um numero na lista
void buscarNumero(Lista *lista, int num) {
    for (int i = 0; i < lista->tamanho; i++) { // Percorre a lista
        if (lista->elementos[i] == num) { // Se encontrar o numero
            printf("Numero %d encontrado na posicao %d.\n", num, i);
            return;
        }
    }
    printf("Numero %d não encontrado na lista.\n", num); // Mensagem se o numero não for encontrado
}

// Funcao para exibir todos os elementos da lista
void exibirLista(Lista *lista) {
    if (lista->tamanho == 0) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    for (int i = 0; i < lista->tamanho; i++) { // Percorre a lista imprimindo os elementos
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int main() {
    Lista lista; // Declaracao da lista
    inicializarLista(&lista); // Inicializa a lista
    int opcao, num;
    
    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Inserir um numero\n");
        printf("2. Remover um numero\n");
        printf("3. Buscar um numero\n");
        printf("4. Exibir todos os elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &num);
                inserirNumero(&lista, num); // Chama a funcao para inserir um numero
                break;
            case 2:
                printf("Digite o numero a ser removido: ");
                scanf("%d", &num);
                removerNumero(&lista, num); // Chama a funcao para remover um numero
                break;
            case 3:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &num);
                buscarNumero(&lista, num); // Chama a funcao para buscar um numero
                break;
            case 4:
                exibirLista(&lista); // Chama a funcao para exibir todos os numeros
                break;
            case 0:
                printf("Encerrando o programa.\n"); // Finaliza o programa
                break;
            default:
                printf("Opcao inválida! Tente novamente.\n"); // Mensagem de erro para opcao inválida
        }
    } while (opcao != 0); // Continua no loop até o usuário escolher sair
    
    return 0;
}
