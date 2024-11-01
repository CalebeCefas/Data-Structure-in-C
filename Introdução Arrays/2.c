#include <stdlib.h>

int main(){
    int valores[5];

    printf("Digite 5 valores inteiros:\n");
    for(int i=0; i<5; i++){
        printf("%d: ", i+1);
        scanf("%d", &valores[i]);
    }

    printf("\nValores armazenados no array:\n");
    for(int i=0; i<5; i++){
        printf("%d: %d\n", i+1, valores[i]);
    }
}