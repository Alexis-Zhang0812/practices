#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *str) {
    int len;
    char *pHead;
    char *pTail;

    len = strlen(str);
    pHead = str;
    pTail = str + len -1;
    if(str == NULL) {
        return;
    }
    while(pHead < pTail) {
        char temp = *pHead;
        *pHead = *pTail;
        *pTail = temp;
        pHead++;
        pTail--;
    }
}

int main(void) {
    char test[] = "abcdefghijk";
    strrev(test);
    printf("%s\n", test);
    return 0;
}
