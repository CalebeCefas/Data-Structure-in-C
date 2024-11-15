#include <stdio.h>

int tamanhoString(const char *str) {
    if (*str == '\0') {
        return 0; // Caso base: fim da string
    }
    return 1 + tamanhoString(str + 1); // Passo recursivo
}

int main() {
    char str[50];

    printf("Digite uma string: ");
    scanf("%49s", str);

    int tamanho = tamanhoString(str);

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
