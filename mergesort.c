#include <stdio.h>

// p start index r end index
void merge(int a[], int p, int r) {
    int mid = (p + r) / 2;          // compute mid here

    int size = r - p + 1;
    int b[size];

    int i = p;
    int j = mid + 1;
    int k = 0;

    // Merge two sorted halves
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while(i <= mid) {              // leftover from left
        b[k++] = a[i++];
    }

    while(j <= r) {                // leftover from right
        b[k++] = a[j++];
    }

    // Copy back to original array
    for(i = p, k = 0; i <= r; i++, k++) {
        a[i] = b[k];
    }
}

void mergeSort(int a[], int p, int r) {
    if(p < r) {
        int mid = (p + r) / 2;

        mergeSort(a, p, mid);
        mergeSort(a, mid + 1, r);

        merge(a, p, r);   // only p and r passed
    }
}

