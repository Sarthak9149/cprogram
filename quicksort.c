#include <stdio.h>

void quickSort(int list[], int first, int last){
    if(first < last){
        int pivot = list[first];  
        int i = first + 1;
        int j = last;
        int temp;

        while(i <= j){
            while(i <= last && list[i] <= pivot)
                i++;

            while(j >= first && list[j] > pivot)
                j--;

            if(i < j){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }

        // place pivot in correct position
        temp = list[first];
        list[first] = list[j];
        list[j] = temp;

        quickSort(list, first, j - 1);
        quickSort(list, j + 1, last);
    }
}

int main(void){
    int array[] = {34, 7, 23, 32, 5, 62};
    quickSort(array, 0, 5);
    printf("Sorted array: \n");
    for(int i = 0; i < 6; i++){
        printf("%d ", array[i]);
    }

}