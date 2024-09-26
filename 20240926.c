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
		printf("���ϴ� �޴��� �����Ͻÿ�(1.�԰�, 2.�Ǹ�, 3.��ǰ��Ȳ, 4.����)\n");
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
	printf("�԰���� �Է� : ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է�2�� ����\n");
	scanf("%d", &j);
	if (j == 1) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", pstock + i);
		}
	}
	else if (j == 2) {
		printf("��ǰID : ");
		scanf("%d", &k);
		printf("\n�԰���� : ");
		scanf("%d", (pstock + k - 1));
	}
}
void f_sell(int* psell) {
	int j;
	int k;
	printf("�Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է�2�� ����\n");
	scanf("%d", &j);
	if (j == 1) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", psell + i);
		}
	}
	else if (j == 2) {
		printf("��ǰID : ");
		scanf("%d", &k);
		printf("\n�Ǹż��� : ");
		scanf("%d", (psell + k - 1));
	}
}
void f_n(int* pstock, int* psell, char(*name)[10]) {
	int x = 0, y = 0;
	int max = 0, min = 0;
	printf("������ : ");
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
	printf("\n�Ǹŷ� : %d(�Ǹ��� %.2f%)\n", y, (float)y / (float)x * 100);
	printf("���� ���� �Ǹŵ� ��ǰ:ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", max + 1, *(name+max), *(psell + max));
	printf("���� ���� �Ǹŵ� ��ǰ:ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", min + 1, *(name + min), *(psell + min));
	for (int i = 0; i < 5; i++) {
		if (*(pstock + i) - *(psell + i) <= 2) {
			printf("��ǰ ID %d: ��ǰ�� : %s : ������(%d)\n", i + 1, *(name + i), *(pstock + i) - *(psell + i));
		}
	}
}
void f_name(char(*pname)[10]) {
	for (int i = 0; i < 5; i++) {
		printf("ID %d ��ǰ�� : ", i + 1);
		scanf("%s", *(pname+i));
		printf("\n");
	}
}