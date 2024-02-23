#include <stdio.h>


void printarr(int *arr, int len) {
    printf("[");
    for (int *i=arr; i<arr+len;i++){
        printf("%d ,",*i);
    }
    printf("]\n");
}


void merge(int *arr, int *m,int len){
    int *first = arr;
    int *second = m;

    // merge array
    int merged[len];
    int *i = merged;


    while (i < merged+len){
        
        /*take item form first sublist IF
         * the item is smaler than the second item and the first pointer is in the first subarray
         * OR the second pointer is bigger than the second subarray
        */
        if ((*first < *second && first < m) || second >= arr+len){
            *i = *first;
            first++;
        }

        //take the second item
        else{
            *i = *second;
            second++;
        }
        i++;
    }
    

    //move the merge array to the original position in memory
    for (int i=0; i < len; i++) {
        *(arr +i)=*(merged +i);
    }
}



void inplacemerge(int *arr, int *m, int len) {

    int *first = arr;
    int *second  = m;


    while (first < m && second < arr+len) {
        
        // first element is in the right place
        if (*first <= *second){
            first++;
        }

        else {
            int *i = second;
            int temp = *second;

            /*
             * - shift all items between the first and second pointer 
             * - move the item from second to the position of first
             */
            while (i != first){
                *i = *(i-1);
                i--;
            }
            *first = temp;
            
            first++;
            second++;
            m++;
        }
    }
}


void mergesort(int *arr, int len){
    if (len > 1){
        mergesort(arr, len/2);
        mergesort(arr+len/2,len-len/2);
        inplacemerge(arr,arr+len/2,len);
        //merge(arr,arr+len/2,len);
    }
}

int main ()
{
    int arr[10] = {1,4,5,8,9,2,3,6,7,0};
    long len = sizeof(arr)/sizeof(int);

    mergesort(arr, len);
    printf("sorted array: ");
    printarr(arr, len);   
    return 0;
}
