#include <stdio.h>
#define LEN 6

void printarr(int *arr, int len) {
    printf("[");
    for (int *i=arr; i<arr+len;i++){
        printf("%d ,",*i);
    }
    printf("]\n");
}

void bubblesort(int *arr, int size){
    int temp;
    for (int step = 0; step < size; step++){
        for (int *i = arr; i<(arr+size-step-1); i++){
            
            if (*i > *(i+1)){
                // swap arr[i] and arr[i+1]
                temp = *(i+1);
                *(i+1)=*i;
                *i=temp;
            }
        }
    }
}


int main() {
    int arr[LEN]  = {6,3,7,2,8,1};
    bubblesort(arr,LEN);
    
    printf("Sorted Array: ");
    printarr(arr, LEN);
    
    return 0;
}
