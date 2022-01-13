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

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;} while(A[i]<= pivot);
        do{j--;} while(A[j]> pivot);

        if(i<j){
            swap(&A[i], &A[j]);
        }
    }while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if(l<h){
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
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

    quickSort(A, 0, n);

    printf("\nSorted Array\n");
    print(A, n);

    return 0;
}
