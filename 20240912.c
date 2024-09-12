#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main() {
    int n, id;
    int max = 0, min = 0;
    int x = 0, y = 0;
    int a[100] = { 0, };
    int b[100] = { 0, };
    int c[100] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        x += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] > b[max]) {
            max = i;
        }
        if (b[i] < b[min]) {
            min = i;
        }
        y += b[i];
        c[i] = a[i] - b[i];
    }
    scanf("%d", &id);
    printf("%d\n", c[id - 1]);
    printf("재고 수량:");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n총 판매량:%d(판매율 %.2f%)\n", y,(float)y/(float)x*100);
    printf("가장 많이 판매된 상품:ID %d,판매량 %d\n", max+1,b[max]);
    printf("가장 적게 판매된 상품:ID %d 판매량 %d\n", min+1, b[min]);
    for (int i = 0; i < n; i++) {
        if (c[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, c[i]);
        }
    }
    return 0;
}