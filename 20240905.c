#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main(){
    int n,id;
    int a[100] = { 0, };
    int b[100] = { 0, };
    int c[100] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        c[i] = a[i] - b[i];
    }
    scanf("%d", &id);
    printf("%d\n", c[id - 1]);
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
