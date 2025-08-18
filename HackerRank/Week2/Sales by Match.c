#include <stdio.h>
#define MAX_COLOR 101  
int sockMerchant(int n, int ar[]) {
    int color_count[MAX_COLOR] = {0};
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        color_count[ar[i]]++;
    }
    for (int i = 1; i < MAX_COLOR; i++) {
        pairs += color_count[i] / 2;
    }
    return pairs;
}
int main() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int result = sockMerchant(n, ar);
    printf("%d\n", result);
    return 0;
}

