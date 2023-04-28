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


int main() {

    int data[] = {5,2,4,6,8,10,15,12,58,23,65};

    insertionSort(data, 11);
    selectionSort(data,11);

    for(int i =0; i<11; i++){
    printf (" %d ", data[i]);
    }

    return 0;
} 
