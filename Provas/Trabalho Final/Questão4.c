int main() {
    No *lista = NULL; // Inicializa a lista como vazia
    int opcao, num;
    
    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Remover elemento\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o número a ser inserido no início: ");
                scanf("%d", &num);
                inserirInicio(&lista, num); // Chama a função para inserir no início
                break;
            case 2:
                printf("Digite o número a ser inserido no final: ");
                scanf("%d", &num);
                inserirFim(&lista, num); // Chama a função para inserir no final
                break;
            case 3:
                printf("Digite o número a ser removido: ");
                scanf("%d", &num);
                removerElemento(&lista, num); // Chama a função para remover um elemento
                break;
            case 4:
                exibirLista(lista); // Chama a função para exibir a lista
                break;
            case 0:
                printf("Encerrando o programa.\n"); // Finaliza o programa
                break;
            default:
                printf("Opção inválida! Tente novamente.\n"); // Mensagem de erro para entrada inválida
        }
    } while (opcao != 0); // Continua no loop até o usuário escolher sair
    
    return 0;
}
