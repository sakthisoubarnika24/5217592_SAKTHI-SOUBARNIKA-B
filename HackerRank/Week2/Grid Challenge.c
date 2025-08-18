#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}
const char* gridChallenge(int n, char grid[][101]) {
    for (int i = 0; i < n; i++) {
        qsort(grid[i], strlen(grid[i]), sizeof(char), cmp_char);
    }
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                return "NO";
            }
        }
    }
    return "YES";
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char grid[n][101];  
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        printf("%s\n", gridChallenge(n, grid));
    }
    return 0;
}