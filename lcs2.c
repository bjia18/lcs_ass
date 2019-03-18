#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int lcs2(int *a, int n,  int *b, int m) {
	//write your code here
	int A[n+1][m+1]; 
   	int i, j; 
   
   	for (i=0; i<=n; i++){ 
     		for (j=0; j<=m; j++){ 
       			if (i == 0 || j == 0) 
         			A[i][j] = 0; 
   
       			else if (a[i-1] == b[j-1]) 
         			A[i][j] = A[i-1][j-1] + 1; 
   
       			else
         			A[i][j] = max(A[i-1][j], A[i][j-1]); 
     		} 
   	} 
   	return A[n][m]; 
	
	//return 0;
}

int main() {
	int n, m;  
  
	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);
	
	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);
	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}
