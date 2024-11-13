#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
void f_stock(struct x* list);
void f_sell(struct x* list);
void f_invidual_crr(struct x* list);
void f_all_crr(struct x* list);
void save(struct x* list,int count);
void load(struct x* list, int size);

struct x {
	int id;
	char name[10];
	int stock;
	int sell;
	int pr;
};
int main(void) {
	int m;
	struct x list[5] = { 0 };
	load(list, 5);
	while (1) {
		printf("원하는 메뉴를 선택하시오(1.입고, 2.판매, 3.개별 현황, 4.전체현황 5.상품정보저장, 6.상품정보가져오기, 7.종료)\n");
		scanf("%d", &m);
		if (m == 1) {
			f_stock(list);
		}
		else if (m == 2) {
			f_sell(list);
		}
		else if (m == 3) {
			f_invidual_crr(list);
		}
		else if (m == 4) {
			f_all_crr(list);
		}
		else if (m == 5) {
			save(list, 5);
		}
		else if (m == 6) {
			load(list, 5);
		}
		else {
			break;
		}
	}
	return 0;
}
void save(struct x* list, int size) {
	FILE* fp = fopen("product.bin", "wb");
	if (fp == NULL) return -1;
	fwrite(list, sizeof(list), size, fp);
	fclose(fp);
	printf("저장 완료\n");
}
void load(struct x* list, int size) {
	FILE* fp = fopen("product.bin", "rb");
	if (fp == NULL) return -1;
	fread(list, sizeof(list), size, fp);
	fclose(fp);
	printf("불러오기 완료");
}
void f_stock(struct x* list) {
	int k;
	printf("상품ID : ");
	scanf("%d", &k);
	list[k - 1].id = k;
	printf("상품명 : ");
	scanf("%s", &list[k - 1].name);
	printf("입고량 : ");
	scanf("%d", &list[k - 1].stock);
	printf("판매가격 : ");
	scanf("%d", &list[k - 1].pr);
}
void f_sell(struct x* list) {
	int k;
	printf("상품 ID : ");
	scanf("%d", &k);
	if (list[k - 1].id == 0) {
		printf("해당 ID 없음.\n");
		return;
	}
	printf("판매 수량 : ");
	scanf("%d", &list[k - 1].sell);
}
void f_invidual_crr(struct x* list) {
	int k;
	printf("상품 ID : ");
	scanf("%d", &k);
	if (list[k - 1].id == 0) {
		printf("해당 ID 없음.\n");
		return;
	}
	printf("상품명 : %s\n", list[k - 1].name);
	printf("가격 : %d\n", list[k - 1].pr);
	printf("입고량 : %d\n", list[k - 1].stock);
	printf("판매량 : %d\n", list[k - 1].sell);
}
void f_all_crr(struct x* list) {
	int x = 0, y = 0;
	int max = 0, min = 0;
	for (int i = 0; i < 10; i++) {
		printf("상품 ID : %d\n", list[i].id);
		printf("상품 이름: %s\n", list[i].name);
		printf("입고량 : %d\n", list[i].stock);
		printf("판매량 : %d\n", list[i].sell);
		printf("가격 : %d\n", list[i].pr);
		printf("-----------------------------\n");
	}
	printf("재고수량 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", list[i].stock - list[i].sell);
		x += list[i].stock;
		y += list[i].sell;
		if (list[i].sell > list[max].sell) {
			max = i;
		}
		if (list[i].sell < list[max].sell) {
			min = i;
		}
	}
	printf("\n판매량 : %d, 판매율 %.2f\n", y, (float)y / (float)x * 100);
	printf("가장 많이 판매된 상품:ID %d, 상품명 : %s, 판매량 %d\n", max + 1, list[max].name, list[max].sell);
	printf("가장 적게 판매된 상품:ID %d, 상품명 : %s, 판매량 %d\n", min + 1, list[min].name, list[min].sell);
	for (int i = 0; i < 10; i++) {
		if (list[i].stock - list[i].sell <= 2) {
			printf("상품 ID %d: 상품명 : %s : 재고부족(%d)\n", i + 1, list[i].name, list[i].stock - list[i].sell);
		}
	}
}