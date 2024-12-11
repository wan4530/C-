#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD    16

void getBinary(char bin[], char str[], int n) {
    for (int i = 0; i < n - strlen(str)+1; i++) {
        bin[i] = '0';
    }
    int j = 0;
    for (int i = n - strlen(str); i < n+1; i++) {
        bin[i] = str[j];
        j++;
    }
}
int bin2dec(char bin[], int n) {
    int dec = 0;
    int  m = 1;
    if (bin[0] == '1') {
        for (int i = 0; i < n; i++) {
            if (bin[i] == '1') {
                bin[i] = '0';
            }
            else if (bin[i] == '0') {
                bin[i] = '1';
            }
        }
        if (bin[n - 1] == '0') {
            bin[n - 1] = '1';
        }
        else {
            bin[n - 1] = '1';
        }
        m = -1;
    }
    int j = 2;
    for (int i = n; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += pow(j, n-i-1);
        }
    }
    return m*dec;
}
int main() {
    char input1[100];
    char input2[100];
    char op[10];

    char binary1[WORD + 1] = { 0 };
    char binary2[WORD + 1] = { 0 };
    
    int result;
    int num1, num2;
    
    printf("<<<<input>>>>\n");
    gets(input1);
    gets(op);
    gets(input2);
    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);
    
    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);

    switch (op[0]) {
    case '+': result = num1 + num2;     break;
    case '-': result = num1 - num2;     break;
    case '*': result = num1 * num2;     break;
    case '/': result = num1 / num2;     break;
    case '%': result = num1 % num2;     break;
    default: printf("bad operator...\n");   break;
    }
    printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);
    return 0;
}