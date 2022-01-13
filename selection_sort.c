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

void selectionSort(int A[], int n)
{
    int i, j, k;

    for(i = 0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j]<A[k])
                k = j;
        }
        // k will point to the smallest value
        swap(&A[i], &A[k]);
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

    selectionSort(A, n);

    printf("\nSorted Array\n");
    print(A, n);

    return 0;
}
