#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
void f_stock(int* pstock);
void f_sell(int* psell);
void f_n(int* pstock, int* psell);
void f_name(char(*pname)[10]);
int main(void) {
	int m = 0;
	int stock[5] = { 0, };
	int sell[5] = { 0, };
	char name[5][100] = { 0, };
	while (1) {
		printf("원하는 메뉴를 선택하시오(1.입고, 2.판매, 3.상품현황, 4.종료)\n");
		scanf("%d", &m);
		if (m == 1) {
			f_stock(&stock);
		}
		else if (m == 2) {
			f_sell(&sell);
		}
		else if (m == 3) {
			f_n(&stock, &sell, name);
		}
		else if (m == 4) {
			f_name(&name);
		}
		else {
			break;
		}
	}
	return 0;
}
void f_stock(int* pstock) {
	int j;
	int k;
	printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력2를 선택\n");
	scanf("%d", &j);
	if (j == 1) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", pstock + i);
		}
	}
	else if (j == 2) {
		printf("상품ID : ");
		scanf("%d", &k);
		printf("\n입고수량 : ");
		scanf("%d", (pstock + k - 1));
	}
}
void f_sell(int* psell) {
	int j;
	int k;
	printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력2를 선택\n");
	scanf("%d", &j);
	if (j == 1) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", psell + i);
		}
	}
	else if (j == 2) {
		printf("상품ID : ");
		scanf("%d", &k);
		printf("\n판매수량 : ");
		scanf("%d", (psell + k - 1));
	}
}
void f_n(int* pstock, int* psell, char(*name)[10]) {
	int x = 0, y = 0;
	int max = 0, min = 0;
	printf("재고수량 : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(pstock + i) - *(psell + i));
		x += *(pstock + i);
		y += *(psell + i);
		if (*(psell + i) > *(psell + max)) {
			max = i;
		}
		if (*(psell + i) < *(psell + min)) {
			min = i;
		}
	}
	printf("\n판매량 : %d(판매율 %.2f%)\n", y, (float)y / (float)x * 100);
	printf("가장 많이 판매된 상품:ID %d, 상품명 : %s, 판매량 %d\n", max + 1, *(name+max), *(psell + max));
	printf("가장 적게 판매된 상품:ID %d, 상품명 : %s, 판매량 %d\n", min + 1, *(name + min), *(psell + min));
	for (int i = 0; i < 5; i++) {
		if (*(pstock + i) - *(psell + i) <= 2) {
			printf("상품 ID %d: 상품명 : %s : 재고부족(%d)\n", i + 1, *(name + i), *(pstock + i) - *(psell + i));
		}
	}
}
void f_name(char(*pname)[10]) {
	for (int i = 0; i < 5; i++) {
		printf("ID %d 상품명 : ", i + 1);
		scanf("%s", *(pname+i));
		printf("\n");
	}
}