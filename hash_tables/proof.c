#include <stdio.h>
void update(int *a, int *b) {
    int *tmp, *tmp1;
    *tmp = *a, *tmp1 = *b;
    *a = *tmp + *tmp1; 
    *b = *tmp1 - *tmp;
    printf("%d\n%d", *a, *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);

    return 0;
}
