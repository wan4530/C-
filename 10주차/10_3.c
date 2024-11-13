#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main(void){
	int array[1000];
	FILE* fp;

	fp = fopen("array.bin", "rb");
	if (fp == NULL) return -1;

	fread(array, sizeof(int), 100, fp);

	for (int i = 0; i < 100; i++) printf("%d ", array[i]);
	fclose(fp);
	return 0;
}