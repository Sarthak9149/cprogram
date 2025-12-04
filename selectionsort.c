#include <stdio.h>

void selectionsort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int minValue = arr[i];
        int minIndex = i;
        for (int j = minIndex; j < n; j++)
        {
            if (arr[j] < minValue)
            {
                minIndex = j;
                minValue = arr[j];
            }
            
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        
    }
    
}


void main(){
    int arr[10] = {29, 10, 14, 37, 13, 5, 42, 1, 19, 8};    
    selectionsort(arr, 10);
}