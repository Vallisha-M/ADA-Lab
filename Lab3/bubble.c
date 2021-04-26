#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
void sort(int arr[], int n)
{
    int i, j;
    for(i =0 ;i<n;i++) {
     for(j=i+1;j<n;j++) {
       if(arr[i]>arr[j]) {
        arr[i] = arr[i]+arr[j];
        arr[j] = arr[i]-arr[j];
        arr[i] = arr[i]-arr[j];
       }
     }
    }

}


void generateArray(int arr[],int n) {
    for(int i=0;i<n;i++)
        arr[i] = (rand()%100) - 50;// -50 to 50
}

void main() {
    srand(time(NULL));
    int n =0;
    printf("Enter length of array : ");
    scanf("%d",&n);
    int arr[n];
    generateArray(arr, n);
    double res;
    clock_t start, end;
    start=clock();
    sort(arr,n);
    end=clock();
    res = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime taken by bubble sort : %lf\n\n",res);
}