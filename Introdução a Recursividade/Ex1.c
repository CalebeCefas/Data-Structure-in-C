#include <stdio.h>

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    return n*fatorial(n-1);
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Fatorial de %d eh %d\n", n, fatorial(n));

    return 0;
}