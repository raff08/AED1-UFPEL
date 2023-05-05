#include <stdio.h>
#include <stdlib.h>

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



int main() {

    int data[] = {23,4,21,-8,90,54,67};

    quickSort(data, 0, 6);
    printf ("%d, %d, %d, %d, %d", data[0], data[1], data[2], data[3], data[4]);

    return 0;
}
