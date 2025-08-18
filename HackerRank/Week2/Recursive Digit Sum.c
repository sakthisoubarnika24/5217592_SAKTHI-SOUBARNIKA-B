#include <stdio.h>
#include <string.h>
long long sumDigits(const char* str) {
    long long sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }
    return sum;
}
int superDigitHelper(long long num) {
    if (num < 10)
        return (int)num;
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return superDigitHelper(sum);
}
int superDigit(const char* n, int k) {
    long long initialSum = sumDigits(n);
    long long total = initialSum * k;
    return superDigitHelper(total);
}
int main() {
    char n[100001]; 
    int k;
    scanf("%s %d", n, &k);
    printf("%d\n", superDigit(n, k));
    return 0;
}
