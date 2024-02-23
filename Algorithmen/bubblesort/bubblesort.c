#include <stdio.h>


void bubblesort(int arr [], int size){
    int temp;
    for (int step = 0; step < size; step++){
        for (int *i = arr; i<arr+size-step; i++){
            
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
    int arr[10]  = {3,6,1,8,2,9,7,4,5,0};
    bubblesort(arr,10);
    
    printf("Sorted Array: ");
    for (int *i=arr; i<arr+10; i++){
        printf("%d,",*i);
    }
    printf("\n");
    
    return 0;
}
