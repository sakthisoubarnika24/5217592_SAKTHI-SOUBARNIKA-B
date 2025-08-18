#include <stdio.h>
#define MAX_VALUE 100  
void countingSort(int arr[], int n, int freq[]) {
    for (int i = 0; i < MAX_VALUE; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int freq[MAX_VALUE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    countingSort(arr, n, freq);
    for (int i = 0; i < MAX_VALUE; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");
    return 0;
}
