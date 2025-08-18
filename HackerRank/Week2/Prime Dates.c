#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
void nextDate(int *d, int *m, int *y) {
    (*d)++;
    int daysInMonth = monthDays[*m - 1];
    if (*m == 2 && isLeap(*y)) daysInMonth = 29;
    if (*d > daysInMonth) {
        *d = 1;
        (*m)++;
        if (*m > 12) {
            *m = 1;
            (*y)++;
        }
    }
}
int isSameDate(int d1, int m1, int y1, int d2, int m2, int y2) {
    return d1 == d2 && m1 == m2 && y1 == y2;
}
int isLucky(int d, int m, int y) {
    char str[20];
    sprintf(str, "%d%d%d", d, m, y); 
    long long num = atoll(str);
    return (num % d == 0 || num % m == 0);
}
int main() {
    char startStr[11], endStr[11];
    scanf("%s %s", startStr, endStr);
    int d1, m1, y1, d2, m2, y2;
    sscanf(startStr, "%d-%d-%d", &d1, &m1, &y1);
    sscanf(endStr, "%d-%d-%d", &d2, &m2, &y2);
    int count = 0;
    while (1) {
        if (isLucky(d1, m1, y1))
            count++;
        if (isSameDate(d1, m1, y1, d2, m2, y2))
            break;
        nextDate(&d1, &m1, &y1);
    }
    printf("%d\n", count);
    return 0;
}