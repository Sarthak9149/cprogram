void bubbleSort(int arr[], int n) { 
    int i, j, temp; 
    for(i = 1; i < n; i++) { 
        for(j = 0; j < n-i; j++) { 
            if( arr[j] > arr[j+1]) { // swap the elements 
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            } 
        }
    }
}