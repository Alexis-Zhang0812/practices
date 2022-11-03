#include <stdio.h>
#include <string.h>

void strrev(char *str) {
    int len = strlen(str);
    for(int i = 0, j = len - 1; i + i < len - 1; i++) {
        char tmp = str[i];
        str[i] = str[j - i];
        str[j - i] = tmp;
    }
}

int main(void) {
    char test[] = "abcdefghijk";
    strrev(test);
    printf("%s\n", test);
    return 0;
}
