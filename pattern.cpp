#include <stdio.h>
void subset(int arr[], int data[], int start, int end, int index, int r) {
    int j, i;
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        subset(arr, data, i+1, end, index+1, r);
    }
}

void printsubset(int arr[], int n, int r) {
    int data[r];
    subset(arr, data, 0, n - 1, 0, r);
}
int main() {
    int arr[] = {1,2,3,4,5}, k=1, n;
    n = 5;
    printsubset(arr, n, k);
    return 0;
}