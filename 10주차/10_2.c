#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 100

int main(void){
	char input[SIZE];
	FILE* fp = NULL;
	int i = 0;

	if ((fp = fopen("output.bin", "rb")) == NULL) {
		printf("error...");
		return 0;
	}
	while (!feof(fp)) {
		fread(&input[i], sizeof(char), 1, fp);
		i++;
	}
	input[--i] = '\0';

	puts(input);
	//fputs(input, fp);
	fclose(fp);
	return 0;
}