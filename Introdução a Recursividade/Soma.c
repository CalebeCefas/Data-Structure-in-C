#include <stdio.h>

int soma(int n, int i){
    if(n == i){
        return n;
    }
    return i+soma(n, i+1);
}

int main(){
    int n,i = 1, sum = 0;
    printf("Digite um numero: ");
    scanf("%d", &n);

    sum = soma(n, i);
    printf("soma dos numeros ate %d eh %d\n", n, sum);

    return 0;
}