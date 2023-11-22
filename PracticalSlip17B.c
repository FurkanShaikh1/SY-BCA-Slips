#include <stdio.h>
#include <string.h>

int main() {
    int n;
    
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    char cities[n][50];  // Array to store city names, assuming each city name is up to 50 characters

    // Input city names
    for (int i = 0; i < n; i++) {
        printf("Enter city %d: ", i + 1);
        scanf("%s", cities[i]);
    }

    char searchCity[50];  // City to search for
    printf("Enter the city you want to search: ");
    scanf("%s", searchCity);

    // Linear search to check if the city is present in the array
    int found = 0;  // 0 represents "not found," 1 represents "found"

    for (int i = 0; i < n; i++) {
        if (strcmp(cities[i], searchCity) == 0) {
            found = 1;
            break;  // City found, no need to continue searching
        }
    }

    if (found) {
        printf("%s is present in the array.\n", searchCity);
    } else {
        printf("%s is not present in the array.\n", searchCity);
    }

    return 0;
}
