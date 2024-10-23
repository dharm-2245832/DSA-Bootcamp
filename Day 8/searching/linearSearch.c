#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, size, target);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    return 0;
}
