#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers and fill an array
void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generates random numbers between 0 and 99
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    generateRandomArray(arr, size);
    
    printf("Randomly generated array:\n");
    printArray(arr, size);
    
    insertionSort(arr, size);
    
    printf("Sorted array using Insertion Sort:\n");
    printArray(arr, size);
    
    return 0;
}
