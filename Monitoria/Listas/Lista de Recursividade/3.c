#include <stdio.h>
#include <stdlib.h>

int fibonacci(int i) {
    if(i == 0){
        return 0;
    } else if(i ==1){
        return 1;
    } else {
        return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(){
    int n;
    printf("Digite o termo da sequencia de fibonacci: ");
    scanf("%d", &n);

    printf("Sequencia de fibonacci:\n");
    for(int i = 0; i<n; i++){
        printf("%d: %d\n", i+1, fibonacci(i));
    }

    return 0;
}