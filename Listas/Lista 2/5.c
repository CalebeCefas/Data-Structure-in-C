/*5. Número de Dígitos:
Escreva uma função recursiva que receba um número inteiro positivo e
retorne o número de dígitos. Exemplo: para 12345, o resultado deve ser */

#include <stdio.h>

int contaDigito(int number){
    if(number>0){
        number/= 10;
        return 1 + contaDigito(number);
    } else {
        return 0;
    }
}

int main(){
    int number, digitos;
    printf("Digite um valor: ");
    scanf("%d", &number);

    digitos = contaDigito(number);
    printf("O valor digitado tem %d digitos", digitos);

    return 0;
}