#include <stdio.h>
int n, d; 
int Free[101], a[101]; 
void out(int a[], int n, int &d);
void Try(int k, int n, int &d);


main(){
	printf("Nhap so phan tu: "); scanf("%d",&n);
	Try(1,n, d);
} 

void out(int a[], int n, int &d){
	printf("%d: ",++d);
	for(int i=1;i<=n;i++){
		printf(" %d", a[i]); 
	} 
	printf("\n"); 
} 

void Try(int k, int n, int &d){
	for(int i=1; i<=n;i++){
		if(Free[i]==0){
			a[k]=i;
			Free[i]=1;
			if(k==n) out(a,n,d);
			else Try(k+1,n, d); 
			Free[i]=0; 
		} 
	} 
} 
