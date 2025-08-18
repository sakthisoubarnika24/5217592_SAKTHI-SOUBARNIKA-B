#include <stdio.h>
#include <stdlib.h>
#define MAX_Q 100000  
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));       
    int* capacities = (int*)calloc(n, sizeof(int));   
    for (int i = 0; i < n; i++) {
        arr[i] = NULL;
    }
    int lastAnswer = 0;
    int result[MAX_Q];
    int resCount = 0;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        if (type == 1) {
            if (sizes[idx] == capacities[idx]) {
                capacities[idx] = capacities[idx] == 0 ? 1 : capacities[idx] * 2;
                arr[idx] = realloc(arr[idx], capacities[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y;
        } else if (type == 2) {
            int value = arr[idx][y % sizes[idx]];
            lastAnswer = value;
            result[resCount++] = lastAnswer;
        }
    }
    for (int i = 0; i < resCount; i++) {
        printf("%d\n", result[i]);
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);
    free(capacities);
    return 0;
}
