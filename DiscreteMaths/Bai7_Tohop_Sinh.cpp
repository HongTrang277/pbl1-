#include <stdio.h>

int a[101], d, n, k; 
int islast(int a[], int k, int n);
void out(int a[], int k, int &d);
void init(int a[],int k);
void Tohop(int a[],int k, int n);
void Sinh(int a[], int n, int &d);


int main(){
	printf("Liet ke to hop chap k cua n.\n"); 
	printf("Nhap k: "); scanf("%d",&k);
	printf("Nhap n: "); scanf("%d", &n);
	Sinh(a, n, d);
} 

void out(int a[], int k, int &d){
	printf("%d: ",++d);
	for(int i=1;i<=k;i++){
		printf(" %d", a[i]); 
	} 
	printf("\n"); 
} 

void init(int a[], int k){
	for(int i=1;i<=k;i++){
		a[i]=i; 
	} 
} 

int islast(int a[], int k, int n){
 	for(int i=1;i<=k; i++){
 		if(a[i]!=n-k+i) return 0;
	 }
	return 1; 
 }

void Tohop(int a[],int k, int n){
	int i=k, j=n;
	if(a[k]==n){
	    while(a[i]==j){
	    	i--;
        	j--; 
	    }
	    a[i]++;
	    do{
	    	a[i+1]=a[i]+1;
	    	i++; 
	    } 
	    while(i==k-1);
    }
    else if(a[k]<n) a[k]++; 
} 

void Sinh(int a[], int n, int &d) 
{
	init(a,n);
	out(a, k, d);
	int stop= islast(a,k, n);
	while (stop == 0) {
		Tohop(a,k, n);
		out(a, k, d);
		stop = islast(a,k, n); 
	} 
}


