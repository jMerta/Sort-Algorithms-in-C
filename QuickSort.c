#include <stdio.h>
#include <stdlib.h>

void Quicksort(int A[], int p, int r);
void write_tab(int A[], int n);
int Partition(int A[], int p, int r);
void swap( int *i, int *j);

int main(int argc, char **argv)
{
    int A[8]={5,7,9,1,3,0,10,2};
    int n = sizeof(A)/sizeof(A[0]);


    write_tab(A, n);
        
    Quicksort(A,0,7);
    printf("\n Tablica posortowana \n");
    
    write_tab(A, n);
    printf("\n");
    getchar();
    return 0;
}


void write_tab (int A[], int n)
{
    int i;
    for (i=0; i<n; i++)
        {
        printf("%d",A[i]);
        printf("\t");
        }

}

void Quicksort(int A[], int p, int r){
	if (p<r){
		int q = Partition(A, p, r);
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);
	}
}



int Partition(int A[],int p,int r)
{
    int j;
    int x = A[r];
    int i = p-1;
    for ( j = p; j <= r-1; j++)
        {
        if (A[j] <= x)
            {
                i = i+1;
                swap (&A[i], &A[j]);
            }
        }
		swap (&A[i+1], &A[r]);
    return i+1;
}

void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}