#include <stdio.h>
#include <stdlib.h>


 void insertionSort(int data[], int size) {
    int i, j, current;
    for (i = 1; i < size; i++) {
        current = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > current) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = current;
    }
}

void selectionSort(int data[], int size) {
    int i, j, min_idx, temp;

    for( i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if(data[j] < data[min_idx]) {
                min_idx = j;
            }
        }

    temp = data[min_idx];
    data[min_idx] = data[i];
    data[i] = temp;

    }
}

void quickSort(int data[], int left, int right) {
    int mid, tmp, i, j;
    i = left;
    j = right;
    mid = data[(left+right)/2];

    do {
        while (data[i] < mid) {
            i++;
        }
        while (mid < data[j]) {
            j--;
        }

        if ( i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) {
        quickSort(data, left, j);
    }
    
    if (i < right) {
        quickSort(data, i, right);
    }
    
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    srand(time(NULL));
    int n, i;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    int arr[n], arr_copy[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        arr_copy[i] = arr[i];
    }

    printf("Vetor original:\n");
    printArray(arr, n);

    printf("\nInsertion Sort:\n");
    insertionSort(arr, n);
    printArray(arr, n);

    printf("\nSelection Sort:\n");
    selectionSort(arr_copy, n);
    printArray(arr_copy, n);

    printf("\nQuick Sort:\n");
    quickSort(arr, 0, n-1);
    printArray(arr, n);

    printf("\nMerge Sort:\n");
    mergeSort(arr_copy, 0, n-1);
    printArray(arr_copy, n);

    return 0;
}
