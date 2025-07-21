#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    int size, new_size, i;
    printf("Enter initial size of array: ");
    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter new size: ");
    scanf("%d", &new_size);
    arr = (int*)realloc(arr, new_size * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    printf("Enter %d elements (enter -1 to skip):\n", new_size);
    for (i = 0; i < new_size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Resized array: ");
    for (i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}