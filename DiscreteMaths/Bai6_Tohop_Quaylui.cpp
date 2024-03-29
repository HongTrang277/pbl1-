#include <stdio.h>

int a[101], n, k, d; 
void Try(int i, int n, int k,  int a[], int &d);
void out(int k, int a[]); 

int main(){
	printf("Liet ke to hop chap k cua n.\n"); 
	printf("Nhap k: "); scanf("%d",&k);
	printf("Nhap n: "); scanf("%d", &n);
	Try(1, n, k, a, d); 
} 

void out( int k, int a[], int &d){
	printf("%d: ",++d);
	for(int i=1;i<=k;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
} 

void Try(int i, int n, int k, int a[], int &d){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
    	a[i]=j;
		if(i==k) out(k, a, d);
		else Try(i+1,n, k, a, d); 
	}
} 
