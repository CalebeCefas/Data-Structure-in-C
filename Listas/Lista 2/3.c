/*3. Sequência de Fibonacci:
Implemente uma função recursiva que calcule o n-ésimo termo da
sequência de Fibonacci. Exemplo: para n = 5, o resultado deve ser 5
(sequência: 0, 1, 1, 2, 3, 5, ...).*/

#include <stdio.h>

int fibonacci(int n){
    if(n == 0) {
        return 0;
    } if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("Os primeiros %d numeros da sequencia de fibonacci:", n);
    for(int i = 0; i<n; i++){
        printf("%d\n", fibonacci(i));
    }

    return 0;
}