#include <stdio.h>

int main() {
    int n, i, j, temp;  // Removed the incorrect "c" declaration
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Array declaration after getting the size

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting logic using Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");  // Added newline for cleaner output
    return 0;
}
