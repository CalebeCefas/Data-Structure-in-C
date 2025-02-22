#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura do nó da lista encadeada
typedef struct No {
    int valor; // Armazena o valor do nó
    struct No *proximo; // Ponteiro para o próximo nó da lista
} No;

// Funcao para inserir um elemento no inicio da lista
void inserirInicio(No **head, int num) {
    No *novoNo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novoNo == NULL) { // Verifica se a alocacao foi bem-sucedida
        printf("Erro ao alocar memória!\n");
        return;
    }
    novoNo->valor = num; // Define o valor do nó
    novoNo->proximo = *head; // Aponta para o antigo primeiro nó
    *head = novoNo; // Atualiza a cabeça da lista para o novo nó
    printf("Numero %d inserido no inicio da lista!\n", num);
}

// Funcao para inserir um elemento no final da lista
void inserirFim(No **head, int num) {
    No *novoNo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novoNo == NULL) { // Verifica se a alocacao foi bem-sucedida
        printf("Erro ao alocar memória!\n");
        return;
    }
    novoNo->valor = num; // Define o valor do nó
    novoNo->proximo = NULL; // O novo nó será o ultimo, então seu próximo é NULL
    
    if (*head == NULL) { // Se a lista estiver vazia, o novo nó será a cabeça
        *head = novoNo;
    } else {
        No *temp = *head;
        while (temp->proximo != NULL) { // Percorre até o final da lista
            temp = temp->proximo;
        }
        temp->proximo = novoNo; // Insere o novo nó no final da lista
    }
    printf("Numero %d inserido no final da lista!\n", num);
}

// Funcao para remover um elemento da lista
void removerElemento(No **head, int num) {
    No *temp = *head, *anterior = NULL;
    while (temp != NULL && temp->valor != num) { // Percorre a lista buscando o elemento
        anterior = temp;
        temp = temp->proximo;
    }
    
    if (temp == NULL) { // Se o numero não for encontrado
        printf("Numero %d não encontrado na lista!\n", num);
        return;
    }
    
    if (anterior == NULL) { // Se o numero estiver na cabeça da lista
        *head = temp->proximo;
    } else {
        anterior->proximo = temp->proximo; // Remove o nó ajustando os ponteiros
    }
    
    free(temp); // Libera a memória do nó removido
    printf("Numero %d removido da lista!\n", num);
}

// Funcao para exibir os elementos da lista
void exibirLista(No *head) {
    if (head == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    while (head != NULL) { // Percorre a lista imprimindo os valores
        printf("%d ", head->valor);
        head = head->proximo;
    }
    printf("\n");
}

int main() {
    No *lista = NULL; // Inicializa a lista como vazia
    int opcao, num;
    
    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no final\n");
        printf("3. Remover elemento\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o numero a ser inserido no inicio: ");
                scanf("%d", &num);
                inserirInicio(&lista, num); // Chama a funcao para inserir no inicio
                break;
            case 2:
                printf("Digite o numero a ser inserido no final: ");
                scanf("%d", &num);
                inserirFim(&lista, num); // Chama a funcao para inserir no final
                break;
            case 3:
                printf("Digite o numero a ser removido: ");
                scanf("%d", &num);
                removerElemento(&lista, num); // Chama a funcao para remover um elemento
                break;
            case 4:
                exibirLista(lista); // Chama a funcao para exibir a lista
                break;
            case 0:
                printf("Encerrando o programa.\n"); // Finaliza o programa
                break;
            default:
                printf("Opcao inválida! Tente novamente.\n"); // Mensagem de erro para entrada inválida
        }
    } while (opcao != 0); // Continua no loop até o usuário escolher sair
    
    return 0;
}
