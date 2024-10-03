#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
int main(void) {
    char src[100];
    char dest[100];
    int result;
    gets(src);
    gets(dest);
    
    result = strcmp(src, dest);
    
    printf("result = %d\n", result);
    return 0;
}