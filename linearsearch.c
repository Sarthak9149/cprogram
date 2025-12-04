#include <stdio.h>

int linear_search(int arr[], int size, int se){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == se){
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[],int size, int se){
    int low = 0, high = size -1;
    while (low <= high)
        {

        int mid = (low + high) / 2;

        if (arr[mid] == se){
            return mid;
        }
        else if (arr[mid] < se)
        {
            low = mid + 1;
        }
        else
        {
            high = mid -1;
        }
    }
    return -1;
}


int main(){
    int arr_linear[] = {1,2,3,4,5,6,7};
    int binary_result = binary_search(arr_linear,7,2);
    if (binary_result == -1)
    {
        printf("element is not present");
    }
    else {
        printf("element is present at index %d", binary_result);
    }
    
}
