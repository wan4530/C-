#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto {
	int number[6];
	int bonus;
	int ID;
}LOTTO;

int dup(LOTTO l, int num, int size) {
	for (int i = 0; i <= size; i++) {
		if (l.number[i] == num) return 1;
	}
	return 0;
}

void initLotto(LOTTO* l) {
	for (int i = 0; i < 6; i++) {
		l->number[i] = 0;
		l->bonus = 0;
		l->ID = 0;
	}
}
LOTTO createAuto(int ID) {
	LOTTO l;
	int num;
	initLotto(&l);
	l.ID = ID;
	for (int i = 0; i < 6; i++) {
		num = rand() % 45+1;
		if (i == 0) l.number[i] = num;
		else if (i > 0 && !dup(l, num, i - 1)) l.number[i] = num;
		else {
			printf("중복발생\n");
			i--;
		}
	}
	return l;
}
LOTTO createManual(int ID) {
	LOTTO l;
	int num;
	initLotto(&l);
	l.ID = ID;
	for (int i = 0; i < 6; i++) {
		printf("input number #%d : ", i + 1);
		scanf("%d", &num);
		if (i == 0) l.number[i] = num;
		else if (i>0 && !dup(l, num, i-1)) l.number[i] = num;
		else i--;
	}
	return l;
}
void printLotto(LOTTO l) {
	printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", l.ID, l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]);
	printf("BONUS : %d\n", l.bonus);
}
LOTTO drawingLotto() {
	LOTTO l;
	int num;
	initLotto(&l);
	for (int i = 0; i < 6; i++) {
		num = rand() % 45 + 1;
		if (i == 0) l.number[i] = num;
		else if (i > 0 && !dup(l, num, i - 1)) l.number[i] = num;
		else {
			printf("중복발생\n");
			i--;
		}
	}
	do {
		l.bonus = rand() % 45 + 1;
	} while (dup(l, l.bonus, 5));

	return l;
}
int matchCount(LOTTO l1, LOTTO l2) {
	int mcount = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (l1.number[i] == l2.number[j]) {
				mcount++;
				printf("%d가 맞았습니다.\n", l1.number[i]);
			}
		}
		//if (l1.number[i] == l2.bonus) mcount++;
	}
	return mcount;
}

int main(int argc, char* argv[]) {

	LOTTO l, l2;
	FILE* fp;
	fp = fopen("20240998.bin", "wb");

	int count;
	srand(time(NULL));
	l = createAuto(20240998);
	//l2 = drawingLotto();
	fwrite(&l, sizeof(LOTTO), 1, fp);
	printLotto(l);
	//printLotto(l2);
	//count = matchCount(l, l2);
	//printf("match : %d\n", count);

	return 0;
}