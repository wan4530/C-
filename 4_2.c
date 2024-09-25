#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main(void) {
	char message2[5] = { 'a', 'b','c','d','\0' };
	char message[5] = { 'a', 'b','c','\0' };
	printf("mesage  = %s, mesage2 = %s", message, message2);
	
	return 0;
}