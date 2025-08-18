#include <stdio.h>
long long sumXor(unsigned long long n) {
    if (n == 0) return 1;
    int zero_bits = 0;
    unsigned long long temp = n;
    while (temp > 0) {
        if ((temp & 1) == 0)
            zero_bits++;
        temp >>= 1;
    }
    long long result = 1LL << zero_bits;

    return result;
}
int main() {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%lld\n", sumXor(n));
    return 0;
}