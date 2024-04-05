#include <stdio.h>

int a[101],b[101], d, n, k; 
void init(int a[],int k);
int islast(int a[], int k, int n);
void out(int a[], int k, int &d);
void Tohop(int a[],int k, int n);
void swap(int &a, int &b);
void Hoanvi(int a[], int n);
int islastHV(int a[], int n);
void SinhHV(int a[], int n, int &d);
void Copy(int a[], int b[], int k);
void Sinh(int a[],int b[], int n, int &d);


int main(){
	printf("Liet ke chinh hop chap k cua n.\n"); 
	printf("Nhap k: "); scanf("%d",&k);
	printf("Nhap n: "); scanf("%d", &n);
	Sinh(a,b, n, d);
} 

void init(int a[], int k){
	for(int i=1;i<=k;i++){
		a[i]=i; 
	} 
} 

int islast(int b[], int k, int n){
 	int j=n; 
	 for(int i=1;i<=k; i++){
 		if(b[i]!=j) return 0;
 		j--; 
	 }
	return 1; 
 }
 
void out(int a[], int k, int &d){
	printf("%d: ",++d);
	for(int i=1;i<=k;i++){
		printf(" %d", a[i]); 
	} 
	printf("\n"); 
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

void swap(int &a, int &b){
	int c=b; b=a; a=c; 
} 

void Hoanvi(int b[], int n){
    int j=n-1;
	while(j>=1 && b[j]>b[j+1]) j--;
	int k=n;
	while(b[j]>b[k]) k--;
	swap(b[j],b[k]);
	int l =j+1, r=n;
	while(l<r){
		swap(b[l], b[r]);
		l++; r--;
	}
} 

int islastHV(int b[], int n){
 	for(int i=1;i<n; i++){
 		if(b[i]<b[i+1]) return 0;
	 }
	return 1; 
 }
 
void SinhHV(int b[], int n, int &d) 
{
	int stop= islastHV(b, n);
	while (stop == 0) {
		Hoanvi(b, n);
		out(b, n, d);
		stop = islastHV(b, n); 
	} 
}

void Copy(int a[], int b[], int k){
	for(int i=1;i<=k;i++){
		b[i]=a[i]; 
	} 
} 

void Sinh(int a[],int b[], int n, int &d){
	init(a,n);
	out(a, k, d);
	Copy(a,b, k); 
	SinhHV(b,k, d);
	int stop= islast(b,k, n);
	while (stop == 0) {
		Tohop(a,k, n);
		out(a, k, d);
		Copy(a,b, k); 
		SinhHV(b,k, d);
		stop = islast(b,k, n); 
	} 
}







