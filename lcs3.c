#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	//write your code here
	int A[n+1][m+1][l+1]; 
  
    for (int i=0; i<=n; i++){ 
        for (int j=0; j<=m; j++){ 
            for (int k=0; k<=l; k++){ 
                
				if (i == 0 || j == 0||k==0) 
                    A[i][j][k] = 0; 
  
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1]) 
                    A[i][j][k] = A[i-1][j-1][k-1] + 1; 
  
                else
                    A[i][j][k] = max(max(A[i-1][j][k], A[i][j-1][k]), A[i][j][k-1]); 
            } 
        } 
    } 
  
    return A[n][m][l]; 
	
	//return 0;
}

int main() {
	int n, m, l;  
  
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
	
	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);
	
	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);
	
	return 0;
}