#include <stdio.h>
#include <string.h>
void timeConversion(char s[]) {
    int hour;
    char ampm[3];
    strncpy(ampm, &s[8], 2);
    ampm[2] = '\0';
    sscanf(s, "%2d", &hour);
    if (strcmp(ampm, "AM") == 0) {
        if (hour == 12)
            hour = 0;      
    } else {
        if (hour !=12)
            hour += 12;
    }
    printf("%02d", hour);
    for (int i =2; i < 8; i++)
        putchar(s[i]);
    printf("\n");
}
int main() {
    char s[11];
    scanf("%s", s);
    timeConversion(s);
    return 0;
}
