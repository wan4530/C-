#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
void f_stock(struct x* list);
void f_sell(struct x* list);
void f_invidual_crr(struct x* list);
void f_all_crr(struct x* list);

struct x{
	int id;
	char name[10];
	int stock;
	int sell;
	int pr;
};
int main(void) {
	int m;
	struct x list[10] = {0};
	while (1) {
		printf("���ϴ� �޴��� �����Ͻÿ�(1.�԰�, 2.�Ǹ�, 3.���� ��Ȳ, 4.��ü��Ȳ 5.����)\n");
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
		else {
			break;
		}
	}
	return 0;
}
void f_stock(struct x* list){
	int k;
	printf("��ǰID : ");
	scanf("%d", &k);
	list[k - 1].id = k;
	printf("��ǰ�� : ");
	scanf("%s", &list[k-1].name);
	printf("�԰� : ");
	scanf("%d", &list[k-1].stock);
	printf("�ǸŰ��� : ");
	scanf("%d", &list[k-1].pr);
}
void f_sell(struct x* list) {
	int k;
	printf("��ǰ ID : ");
	scanf("%d", &k);
	if (list[k - 1].id == 0) {
		printf("�ش� ID ����.\n");
		return;
	}
	printf("�Ǹ� ���� : ");
	scanf("%d", &list[k - 1].sell);
}
void f_invidual_crr(struct x* list) {
	int k;
	printf("��ǰ ID : ");
	scanf("%d", &k);
	if (list[k - 1].id == 0) {
		printf("�ش� ID ����.\n");
		return;
	}
	printf("��ǰ�� : %s\n", list[k - 1].name);
	printf("���� : %d\n", list[k - 1].pr);
	printf("�԰� : %d\n", list[k - 1].stock);
	printf("�Ǹŷ� : %d\n", list[k - 1].sell);
}
void f_all_crr(struct x* list) {
	int x = 0, y = 0;
	int max = 0, min = 0;
	for (int i = 0; i < 10; i++) {
		printf("��ǰ ID : %d\n", list[i].id);
		printf("��ǰ �̸�: %s\n", list[i].name);
		printf("�԰� : %d\n", list[i].stock);
		printf("�Ǹŷ� : %d\n", list[i].sell);
		printf("���� : %d\n", list[i].pr);
		printf("-----------------------------\n");
	}
	printf("������ : ");
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
	printf("\n�Ǹŷ� : %d, �Ǹ��� %.2f\n", y, (float)y / (float)x * 100);
	printf("���� ���� �Ǹŵ� ��ǰ:ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", max + 1, list[max].name, list[max].sell);
	printf("���� ���� �Ǹŵ� ��ǰ:ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", min + 1, list[min].name, list[min].sell);
	for (int i = 0; i < 10; i++) {
		if (list[i].stock - list[i].sell <= 2) {
			printf("��ǰ ID %d: ��ǰ�� : %s : ������(%d)\n", i + 1, list[i].name, list[i].stock - list[i].sell);
		}
	}
}