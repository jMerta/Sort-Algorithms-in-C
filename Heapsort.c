#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void write_tab(int A[], int n);
void create_tab(int A[], int n);
void heapsort(int A[], int n);
void heapify(int A[],  int i, int n);
void buildHeap(int A[], int n );
void swap( int *i, int *j);

int main(int argc, char **argv)
{
    int A[500000];
    int n = 500000;
    create_tab(A, n);
/*    write_tab(A,  n);*/
    clock_t t;
    t = clock();
    heapsort(A,n);
     t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
/*    printf("\n\n After sorting");
    write_tab( A,  n);*/
    
    printf("\nTime taken %lf seconds ", time_taken);
    getchar();
	return 0;
}
void buildHeap(int A[], int n)
{

    int i = n/2;
    while(i > 0) heapify(A, --i,n);
}

void create_tab(int A[], int n)
{

    int i;
    srand(time(0));
    for(i=0; i<n;i++)
    {
        A[i]=rand() %10001;
    }
}

void write_tab (int A[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf("%d",A[i]);
        printf("\t");
    }
    
}
void heapify(int A[], int i, int n)
{
    
    int left = -1;
    int right = -1;
    int largest = i;
    
    if(2*i+1<n) left = 2*i+1;
    if(2*i + 2<n) right = 2*i + 2;
    
    if(left < 0 && right < 0) return;
    if(left < 0) left = right;
    if(right < 0) right = left;
    
    if(A[left] > A[i]) largest = left;
    if(A[right] > A[largest]) largest = right;
    if(largest != i)
  {
    swap(&A[i], &A[largest]);
    heapify(A, largest, n);
  }
}

void heapsort( int A[], int n)
{
    int i;
    int heapsize = n;
    for( i = heapsize/2; i>=0; i--){
        heapify(A,i,n);
    }
    for (i = heapsize; i>0; i--){
        swap(&A[0],&A[i]);
        heapsize--;
        heapify(A,0,heapsize);
    }
}
void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}