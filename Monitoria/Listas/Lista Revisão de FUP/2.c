#include <stdio.h>

int main() {
    int i=5, *p;
    p = &i;

    int **p = &p;
    printf("%d %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);

    return 0;
}
/*
p -> endereço de memória de i;
*p+2 -> valor de i +2;
**&p -> valor de i;
3**p -> 3 vezes o valor de i;
**&p+4 -> valor de i +4;
*/