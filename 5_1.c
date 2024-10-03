#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>
int main(void) {
    char src[100];
    char dest[100];
    int length;
    gets(src);
    length = strlen(src);
    printf("length of src = %d\n", length);
    strcpy(dest, src);
    printf("src = %s, dest = %s\n",src,dest);
    strcat(dest, src);
    printf("src = %s, dest = %s\n", src, dest);
    return 0;
}