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
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Sequencia de fibonacci:\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", fibonacci(i));
    }

    return 0;
}