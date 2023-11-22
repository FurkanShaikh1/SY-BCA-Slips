#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of n integers.
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random integers between 0 and 99
    }
}

// Function to perform binary search on a sorted array.
int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x) {
            return mid; // Element found at index 'mid'
        }
        
        if (arr[mid] < x) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Element not found
}

int main() {
    int n, x;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    generateRandomArray(arr, n);
    
    // Sort the array (you can use any sorting algorithm of your choice)
    // For simplicity, we'll use bubble sort here.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nEnter the number to search: ");
    scanf("%d", &x);
    
    int result = binarySearch(arr, n, x);
    
    if (result != -1) {
        printf("%d found at index %d.\n", x, result);
    } else {
        printf("%d not found in the array.\n", x);
    }
    
    return 0;
}
