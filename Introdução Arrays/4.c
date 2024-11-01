#include <stdlib.h>

int main(){
    int valores[5], maior = 0, menor = 10000000000;

    printf("Digite 5 valores inteiros:\n");
    for(int i=0; i<5; i++){
        printf("%d: ", i+1);
        scanf("%d", &valores[i]);
        
        if(valores[i]>maior){
            maior = valores[i];
        } if(valores[i]<menor){
            menor = valores[i];
        }
    }

    printf("Maior valor: %d\nMenor valor: %d", maior, menor);
}