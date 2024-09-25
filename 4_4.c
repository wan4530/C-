#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main(void) {
	int ch;
	char message[100];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		message[i++] = ch;
	}
	message[i] = '\0';
	printf("%s", message);
	return 0;
}