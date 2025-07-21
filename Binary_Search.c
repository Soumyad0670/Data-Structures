#include <stdio.h>
int main() {
    int array[100], size, i, searchElement;
    int left, right, mid;
    int found = 0;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter %d elements in ascending order:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &searchElement);
    left = 0;
    right = size - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(array[mid] == searchElement) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(array[mid] < searchElement) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if(!found) {
        printf("Element not found in array\n");
    }
    return 0;
}
