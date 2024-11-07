#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
int getline(char* line) {
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main(void) {
	char input[100];
	FILE* fp;
	if (((fp = fopen("output.txt", "r")) == NULL)) {
		printf("error...");
		return 0;
	}
	while (!feof(fp)) {
		fgets(input, 100, fp);
		printf("%s", input);
	}
	fclose(fp);
	return 0;
}
