// Função para inverter a lista encadeada
void inverterLista(No **head) {
    No *anterior = NULL;  // Ponteiro para armazenar o nó anterior
    No *atual = *head;    // Ponteiro para o nó atual, começando da cabeça
    No *proximo = NULL;   // Ponteiro para armazenar o próximo nó temporariamente
    
    while (atual != NULL) {  // Percorre a lista até o final
        proximo = atual->proximo;  // Armazena o próximo nó antes de alterar os ponteiros
        atual->proximo = anterior; // Inverte o ponteiro do nó atual para apontar para o anterior
        anterior = atual;  // Move o ponteiro "anterior" para o nó atual
        atual = proximo;   // Avança para o próximo nó
    }
    
    *head = anterior; // Atualiza a cabeça da lista para o novo primeiro elemento
    printf("Lista invertida com sucesso!\n");
}
