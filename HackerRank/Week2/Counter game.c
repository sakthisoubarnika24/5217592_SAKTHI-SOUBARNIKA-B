#include <stdio.h>
int isPowerOfTwo(unsigned int n) {
    return (n && !(n & (n - 1)));
}
unsigned int highestPowerOfTwoLessThan(unsigned int n) {
    unsigned int p = 1;
    while (p << 1 < n) {
        p <<= 1;
    }
    return p;
}
const char* counterGame(unsigned int n) {
    int turn = 0; 
    while (n != 1) {
        if (isPowerOfTwo(n)) {
            n = n / 2;
        } else {
            unsigned int hp = highestPowerOfTwoLessThan(n);
            n = n - hp;
        }
        turn = 1 - turn; 
    }
    return (turn == 0) ? "Richard" : "Louise";
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned int n;
        scanf("%u", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}