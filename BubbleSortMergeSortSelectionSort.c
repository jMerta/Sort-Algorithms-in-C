#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubblesort (int A[10], int n);
void selectionsort (int A[10], int n);
void write_tab(int A[10], int n);
void create_tab(int A[10], int n);
void swap( int *i, int *j);
void merge(int *A, int *j, int left, int *p, int right);
void mergesort(int *A, int n);

int main(int argc, char **argv)
{
    char znak;
	do {
    int n, A[10];
    printf("Enter size of the table for bubble-sort: ");
    scanf("%d",&n);
    create_tab(A,n);
    printf("\nTable before sorting: ");
    write_tab(A,n);
    bubblesort(A,n);
    printf("\nTable after bubble-sort: ");
    write_tab(A,n);
    
    
    printf("\n\nEnter size of the table for selection sort: ");
    scanf("%d",&n);
    create_tab(A,n);
    printf("\nTable before sorting: ");
    write_tab(A,n);
    selectionsort(A,n);
    printf("\nTable after selection sort: ");
    write_tab(A,n);
    
    
    
    printf("\n\nEnter size of the table for merge sort: ");
    scanf("%d",&n);
    create_tab(A,n);
    printf("\nTable before sorting: ");
    write_tab(A,n);
    mergesort(A,n);
    printf("\nTable after selection sort: ");
    write_tab(A,n);
    
    
    
    
    
    printf("\n\nDo you wish to repeat Y/N?\n\n");
    znak = getch();
    }
    while (znak == 'y' || znak == 'Y');
	return 0;
}

void bubblesort(int A[], int n){
    int i,j,temp;
    for ( i =0; i<n-1; i++){
        for (j=0; j<n-1-i;j++)
        {
            if (A[j] > A[j+1])
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void create_tab(int A[], int n)
{

    int i;
    srand(time(0));
    for(i=0; i<n;i++)
    {
        A[i]=rand() %101;
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

void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}


void selectionsort(int A[], int n)
{
    int i,j;
    for (i =0; i<n; i++){
        for (j=0;j<n-1;j++){
            if (A[j]>A[j+1])
            {
                swap (&A[j], &A[j+1]);
            }
        }
    }
}


void merge (int *A, int *L, int left, int *P, int right)
{
    int i=0,j=0,k=0; // i <- lewa tabela, j <- prawa tabela, k <- scalona tabela

    while(i<left && j < right){
        if(L[i] < P[j]) {
            A[k++] = L[i++];
        }
        else {
            A[k++] = P[j++];
        }
    }
    while(i < left) {
        A[k++]= L[i++];
    }
    while(j < right) {
        A[k++] = P[j++];
    }
    
}

void mergesort(int *A, int n){
    int i,k,*L,*P;
    
    if(n < 2) {
        return;
    }
    k = n/2; //srodek tabeli by podzelic na dwie tabele
    
    L =(int*)malloc(k*sizeof(int));   // funkcja przydziela pamięc dla nmeb elemtów
    P =(int*)malloc((n-k)*sizeof(int));
    
    for(i = 0; i<k;i++){
        L[i] = A[i];
    }
    for(i = k; i<n; i++){
        P[i-k] = A[i];
    }
    mergesort(L,k);
    mergesort(P,n-k);
    merge(A,L,k,P,n-k);
    free(L);
    free(P);
}