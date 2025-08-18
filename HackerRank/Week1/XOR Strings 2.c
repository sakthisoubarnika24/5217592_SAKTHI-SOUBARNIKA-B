#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], result[100];
    scanf("%s", a);
    scanf("%s", b);

    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] == b[i])
            result[i] = '0';
        else
            result[i] = '1';
    }
    result[len] = '\0';

    printf("%s\n", result);
    return 0;
}
