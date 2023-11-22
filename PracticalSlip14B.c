#include <stdio.h>
#include <string.h>

void bubbleSort(char names[][50], int n) {
    int i, j;
    char temp[50];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Compare adjacent names and swap them if they are out of order
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);

    char names[n][50];

    // Input names from the user
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort the names using bubble sort
    bubbleSort(names, n);

    // Display the sorted names
    printf("Sorted names in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
