#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char names[][50], int low, int high) {
    char pivot[50];
    strcpy(pivot, names[high]);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(names[j], pivot) <= 0) {
            i++;
            swap(names[i], names[j]);
        }
    }

    swap(names[i + 1], names[high]);
    return i + 1;
}

void quickSort(char names[][50], int low, int high) {
    if (low < high) {
        int pi = partition(names, low, high);
        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }
}

int main() {
    char names[][50] = {"John", "Alice", "Bob", "Mary", "David", "Emma", "Frank"};
    printf("%d", names[0]);
    int n = sizeof(names) / sizeof(names[0]);

    quickSort(names, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}