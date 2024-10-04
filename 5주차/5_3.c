#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
int main(void) {
    char input[200] = "";
    int count[26] = { 0, };
    int ch;
    int i = 0;

    while ((ch = getchar()) != EOF) {
        input[i++] = ch;
    }
    i = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            count[input[i]-'a']++;
        }
        i++;
    }
    printf("ÀÔ·Â¹®ÀÚ¿­ : %s\n", input);
    for (int i = 0; i < 26; i++) {
        printf("%c ÃâÇöÈ½¼ö : %d\n", 'a' + i, count[i]);
    }
    return 0;
}
