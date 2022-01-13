#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// using swap function
void insertionSort(int A[], int n)
{
    int i, j;

    for(i=1; i<n; i++){
        for(j=i; j>0 && A[j]< A[j-1]; j--){
            swap(&A[j], &A[j-1]);
        }
    }
}

// without using swap
void insertionSort1(int A[], int n)
{
    int i, j, x;

    for(i=1; i<n; i++){
        x = A[i];
        j = i-1;
        while(j>-1 && A[j]> x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void print(int A[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {96, 113, 107, 212, 89, 14, 332, 150, 38, 19, 10};
    int n = sizeof(A)/sizeof(A[0]);

    printf("Unsorted array\n");
    print(A, n);

    insertionSort(A, n);

    printf("\nSorted Array\n");
    print(A, n);

    return 0;
}
