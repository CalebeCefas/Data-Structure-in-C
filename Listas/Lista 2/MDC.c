/*5.
Máximo Divisor Comum (MDC):
Crie uma função recursiva para calcular o MDC de dois números usando
o algoritmo de Euclides. Exemplo: o MDC de 48 e 18 é 6.
*/

#include <stdio.h>

int calcularMDC(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calcularMDC(b, a % b);
}

int main() {
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    
    int mdc = calcularMDC(num1, num2);
    printf("O MDC de %d e %d é: %d\n", num1, num2, mdc);

    return 0;
}
