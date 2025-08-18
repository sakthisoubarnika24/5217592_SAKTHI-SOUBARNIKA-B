#include <stdio.h>
int towerBreakers(int n, int m) {
    if (m == 1 || n % 2 == 0) {
        return 2; 
    } else {
        return 1;  
    }
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int winner = towerBreakers(n, m);
        printf("%d\n", winner);
    }
    return 0;
}