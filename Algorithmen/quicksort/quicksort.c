#include <stdio.h>


void swapint(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}


void printarr(int *arr, int len) {
    printf("[");
    for (int *i=arr; i<arr+len;i++){
        printf("%d ,",*i);
    }
    printf("]\n");
}


void quicksort(int *arr, int len){
    if (len>1) {
        int *pivot = arr;
        int *i = arr+1;
        int *j = arr + len-1;

        while (i<=j) {
            while (*i < *pivot) i++;
            while (*j > *pivot) j--;
        
            if (*i > *j && i<j){         
            swapint(i, j);
            i++;
            j--;
            }
        }

        swapint(pivot, j);

        quicksort(arr, j-arr);
        quicksort(j+1, len - (j-arr)-1);
    }
}

int main ()
{
    int arr[10] = {4,1,5,8,9,2,3,6,7,0};
    
    quicksort(arr, 10);
    
    printf("sorted array: ");
    printarr(arr, 10);   
    
    return 0;
}
