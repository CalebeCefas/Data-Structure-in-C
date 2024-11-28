#include <stdio.h>
#include <string.h>

void inverteString(char *str, int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    char temp = str[0];
    str[0] = str[tamanho - 1];
    str[tamanho - 1] = temp;

    str[tamanho - 1] = '\0';
    inverteString(str + 1, tamanho - 2);
    str[tamanho - 1] = temp;
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%99s", str);

    int tamanho = strlen(str);
    inverteString(str, tamanho);

    printf("String invertida: %s\n", str);

    return 0;
}
