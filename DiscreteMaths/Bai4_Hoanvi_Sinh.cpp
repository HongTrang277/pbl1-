#include <stdio.h>

int a[101], d; 
int islast(int a[], int n);
void out(int a[], int n, int &d);
void init(int a[], int n);
void swap(int &a, int &b);
void Hoanvi(int a[], int n);
void Sinh(int a[], int n, int &d);


int main(){
	int n; 
	printf("Nhap so phan tu: "); scanf("%d", &n);
	Sinh(a, n, d);
} 

void out(int a[], int n, int &d){
	printf("%d: ",++d);
	for(int i=1;i<=n;i++){
		printf(" %d", a[i]); 
	} 
	printf("\n"); 
} 

void init(int a[], int n){
	for(int i=1;i<=n;i++){
		a[i]=i; 
	} 
} 

void swap(int &a, int &b){
	int c=b; b=a; a=c; 
} 

int islast(int a[], int n){
 	for(int i=1;i<n; i++){
 		if(a[i]<a[i+1]) return 0;
	 }
	return 1; 
 }

void Hoanvi(int a[], int n){
    int j=n-1;
	while(j>=1 && a[j]>a[j+1]) j--;
	int k=n;
	while(a[j]>a[k]) k--;
	swap(a[j],a[k]);
	int l =j+1, r=n;
	while(l<r){
		swap(a[l], a[r]);
		l++; r--;
	}
} 

void Sinh(int a[], int n, int &d) 
{
	init(a,n);
	out(a, n, d);
	int stop= islast(a, n);
	while (stop == 0) {
		Hoanvi(a, n);
		out(a, n, d);
		stop = islast(a, n); 
	} 
}


