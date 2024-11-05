#include <stdlib.h>
#include <stdio.h>

int soma(int a, int b){
    return a + b;
}

int multiplicacao(int a, int b){
    return a * b;
}

int executaOperacao(int (*operacao)(int, int), int x, int y){
    return operacao(x, y);
}

void questao1(){
    int i, *ptri = &i;

    printf("Digite um valor inteiro: ");
    scanf("%d", &i);

    printf("Valor digitado: %d\nEndereco do valor: %p\n", i, (void*)ptri);

    return;
}

void questao2(int *ptrj, int *ptrk) {
    int aux = *ptrj;
    *ptrj = *ptrk;
    *ptrk = aux;

    printf("Valor trocado de j: %d\nValor trocado de k: %d\n", *ptrj, *ptrk);

    return;
}

void questao3(){
    int array[5];

    for(int i = 0; i<5; i++){
        printf("Digite o dado %d de 5: ", i+1);
        scanf("%d", &array[i]);
    } for(int i = 0; i<5; i++){
        printf("Dado %d de 5: %d\n", i+1, array[i]);
        printf("Endereco de dado %d de 5: %d", i+1, &array[i]);
        printf("\n\n");
    }

    return;
}

void questao4() {
    int n, *array;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Digite dado %d de %d: ", i+1, n);
        scanf("%d", &array[i]);
    }

    printf("Valores do array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

void questao5() {
    int x, y, resultado;
    char operacao;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &x, &y);

    printf("Escolha a operação ('+' para soma, '*' para multiplicação): ");
    scanf(" %c", &operacao);

    if (operacao == '+') {
        resultado = executaOperacao(soma, x, y);
    } else if (operacao == '*') {
        resultado = executaOperacao(multiplicacao, x, y);
    } else {
        printf("Operação inválida!\n");
        return;
    }

    printf("Resultado da operação: %d\n", resultado);
}

int main() {
    int x;
    printf("Digite a questao a ser visualizada: ");
    scanf("%d", &x);
    printf("\n");

    if(x == 1) {
        questao1();
    } else if(x == 2) {
        int j, k, *ptrj = &j, *ptrk = &k;

        printf("Digite um valor para j: ");
        scanf("%d", &j);
        printf("Digite um valor para k: ");
        scanf("%d", &k);

        questao2(ptrj, ptrk);
    } else if(x == 3) {
        questao3();
    } else if(x == 4) {
        questao4();
    } else if(x == 5) {
        questao5();
    } else {
        printf("Questão inválida!\n");
    }

    return 0;
}