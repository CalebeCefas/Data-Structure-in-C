#include <stdlib.h>

int main(){
    int valores[5], soma = 0;

    printf("Digite 5 valores inteiros:\n");
    for(int i=0; i<5; i++){
        printf("%d: ", i+1);
        scanf("%d", &valores[i]);
        soma += valores[i];
    }
    printf("Soma dos valores: %d", soma);
}