#include <stdio.h>

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisão por zero não permitida.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int opcao;
    float num1, num2, resultado;

    do {
        printf("\nCalculadora Simples\n");
        printf("1: Soma\n");
        printf("2: Subtração\n");
        printf("3: Multiplicação\n");
        printf("4: Divisão\n");
        printf("5: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite o primeiro número: ");
            scanf("%f", &num1);
            printf("Digite o segundo número: ");
            scanf("%f", &num2);
        }

        switch (opcao) {
            case 1:
                resultado = soma(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                resultado = subtracao(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                resultado = multiplicacao(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                resultado = divisao(num1, num2);
                if (num2 != 0) {
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
            case 5:
                printf("Saindo da calculadora.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
