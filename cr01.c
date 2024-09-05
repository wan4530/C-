#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main(){
    int n;
    int a[100] = { 0, };
    int b[100] = { 0, };
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d ", &b[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        a[i] -= b[i];
    }
    printf("%d\n", a[x - 1]);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}