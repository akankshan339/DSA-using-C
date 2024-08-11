//. Write a C program to sort a sequence of characters given by user in an array, using Quick sort technique
#include <stdio.h>
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    char arr[size];
    printf("Enter the characters: ");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    return 0;
}