#include <stdio.h>
#include <string.h>
#include <ctype.h>
void caesarCipher(char* s, int k) {
    int len = strlen(s);
    k = k % 26;  
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (isupper(ch)) {
            s[i] = ((ch - 'A' + k) % 26) + 'A';
        } else if (islower(ch)) {
            s[i] = ((ch - 'a' + k) % 26) + 'a';
        }
    }
    printf("%s\n", s);
}
int main() {
    int n, k;
    char s[101];  
    scanf("%d", &n);   
    scanf("%s", s);   
    scanf("%d", &k);   
    caesarCipher(s, k);
    return 0;
}
