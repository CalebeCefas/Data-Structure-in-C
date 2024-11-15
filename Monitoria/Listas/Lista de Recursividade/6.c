#include <stdio.h>

int contaOcorrencias(const char *str, char c) {
    if (*str == '\0') {
        return 0;
    }

    return (*str == c) + contaOcorrencias(str + 1, c);
}

int main() {
    char str[100];
    char c;

    printf("Digite uma string: ");
    scanf("%99s", str);

    printf("Digite o caractere para contar: ");
    scanf(" %c", &c);

    int ocorrencias = contaOcorrencias(str, c);

    printf("O caractere '%c' aparece %d vez(es) na string \"%s\".\n", c, ocorrencias, str);

    return 0;
}
