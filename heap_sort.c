#include <stdio.h>

int exchange(int A[], int idx1, int idx2)
{
    int C = A[idx1];
    A[idx1] = A[idx2];
    A[idx2] = C;
    return 0;
}
int max_heapify(int A[], int idx,int n)
{
    int largest;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    if(l<n && A[l]>A[idx])
    largest = l;
    else largest = idx;
    if(r<n && A[r]>A[largest])
    largest = r;
    if(largest!=idx)
    {
        exchange(A,idx,largest);
        max_heapify(A,largest,n);
    }
    return 0;
}
int build_max_heap(int A[],int n)
{
    int i;
    for(i=n/2 - 1 ; i>= 0 ; i--)
    {
        max_heapify(A,i,n);
    }
    return 0;
}
int heap_sort(int A[],int n)
{
    int i;
    build_max_heap(A,n);
    for (i=n-1 ; i>=1 ; i--)
    {
        exchange(A, 0, i);
        n = n-1;
        max_heapify(A,0,n);
    }
    return 0;
}
int main()
{
    int i, A[] = {23, 100, 39, 111};
    int n = sizeof(A)/sizeof(A[0]);
    heap_sort(A,n);



    n = sizeof(A)/sizeof(A[0]);
    for(i = 0; i<n ; i++)
    printf("%d\t",A[i]);
    return 0;
}

#include <stdio.h>
int partition(int a[],int p,int q) {
    int x = a[p];
    int i=p,j;
    for(j=i+1;j<=q;j++) {
        if(a[j] <=x) {
            i++;
            swap
        }
    }
}
int main() {

}
"font_face": "DejaVu Sans Mono",