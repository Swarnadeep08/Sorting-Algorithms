#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l; j = mid+1; k = l;
    int B[h+1];

    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i<=mid; i++) B[k++] = A[i];
    for(; j<=h; j++) B[k++] = A[j];

    // copy the elements back to A from B
    for(i=l; i<=h; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        mergeSort(A, l, mid);
        mergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

void iterativeMergeSort(int A[], int n)
{
    int p, i, l, h, mid;

    for(p=2; p<=n; p=2*p){
        for(i=0; i+p-1<=n; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
    }

    if(p/2 < n)
        Merge(A, 0, p/2-1, n-1);
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

    mergeSort(A, 0, n-1);

    printf("\nSorted Array\n");
    print(A, n);

    return 0;
}
