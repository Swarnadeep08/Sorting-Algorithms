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

void bubbleSort(int A[], int n)
{
    int i, j, flag=0;

    for(i=0; i<n-1; i++){
        flag = 0;
        for(j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag++;
            }
        }
        if(flag==0)
            break;
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
    int A[] = {96, 113, 107, 212, 89, 14, 332, 150, 38, 19, 11};
    int n = sizeof(A)/sizeof(A[0]);

    printf("Unsorted array\n");
    print(A, n);

    bubbleSort(A, n);

    printf("\nSorted Array\n");
    print(A, n);

    return 0;
}
