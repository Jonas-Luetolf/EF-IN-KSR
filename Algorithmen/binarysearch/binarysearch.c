#include <stdio.h>
#include <stdlib.h>


int* binarysearch(int *low, int len, int element){
    int *up = low + len;
    if (len == 1){
        exit(-1);
    } 

    int *mid = low + ((up - low) / 2);

    if (element == *mid) {
        return mid;
    }

    else if (element < *mid){
        return binarysearch(low, mid - low, element);
    }

    else if (element > *mid){
        return binarysearch(mid, up - mid, element);
    }

    exit(-1);
}



int main ()
{
    int arr[7] = {0,2,3,5,6,7,9};
    int *ptr = binarysearch(arr, 7, 9);
    long index = ptr - arr;
    
    printf("Array: ");
    for (int *i = arr; i<arr+7; i++){
        printf("%d,",*i);
    }
    printf("\n");
   
    printf("Element: %d found at pos: %ld \n",*ptr, index);
    return 0;
}
