#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

//int atoi(char* num);
int main(int argc, char* argv[]) {

	int a, b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("a+b = %d", a + b);
	return 0;
}