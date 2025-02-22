#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista encadeada
struct Node {
    int data;           // Dado armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó
};

// Funçao para inserir um valor na lista encadeada
void inserir(struct Node** head, int valor) {
    // Variável temporária para percorrer a lista
    struct Node* temp = *head;

    // Verifica se o valor já existe na lista
    while (temp != NULL) {  // Enquanto houver elementos na lista
        if (temp->data == valor) {  // Se o valor já estiver presente
            printf("Nao pode adicionar elementos iguais\n");  // Mensagem de erro
            return;  // Nao faz nada e retorna
        }
        temp = temp->next;  // Move para o próximo nó
    }

    // Se o valor nao for encontrado, cria um novo nó
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));  // Aloca memória para o novo nó
    novoNode->data = valor;    // Atribui o valor ao novo nó
    novoNode->next = *head;    // O próximo do novo nó é o nó atual que estava no início (head)

    // Atualiza o ponteiro head para o novo nó, inserindo ele no início da lista
    *head = novoNode;
}

// Funçao para imprimir a lista encadeada
void imprimir(struct Node* head) {
    struct Node* temp = head;  // Variável temporária para percorrer a lista

    // Percorre e imprime cada nó da lista
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Imprime o dado do nó atual
        temp = temp->next;  // Move para o próximo nó
    }

    printf("NULL\n");  // Indica o fim da lista
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia

    // Testando a inserçao de valores
    inserir(&head, 10);  // Insere 10
    inserir(&head, 20);  // Insere 20
    inserir(&head, 10);  // Tenta inserir 10 novamente (duplicado)

    imprimir(head);  // Exibe a lista final

    return 0;
}
