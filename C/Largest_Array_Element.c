#include<stdio.h>


int returnMax(int array[], int n){
    int max=0;
    for(int i = 0; i<n; i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
}

int returnMin(int array[], int n){
    int min = 32767;
    for(int i = 0; i<n; i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
}
int main(){
    int arr[] = {1, 12 , 3, 54, 5, 67, 654};
    int max = returnMax(arr, 7);
    printf("The maximum element of the array is %d\n", max);

    int min = returnMin(arr, 7);
    printf("The minimum element of the array is %d\n", min);

    return 0;
}
