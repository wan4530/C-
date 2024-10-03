#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int number[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		number[i] = rand();
		printf("number = %d\n", number[i]);
	}
	return 0;
}
