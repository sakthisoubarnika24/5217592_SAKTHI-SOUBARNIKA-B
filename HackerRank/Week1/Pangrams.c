#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ALPHABET_COUNT 26
const char* pangrams(char *s) {
    int letters[ALPHABET_COUNT] = {0};
    int index;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            index = tolower(s[i]) - 'a';
            letters[index] = 1;
        }
    }
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (letters[i] == 0) {
            return "not pangram";
        }
    }
    return "pangram";
}
int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    printf("%s\n", pangrams(s));
    return 0;
}
