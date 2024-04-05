#include <stdio.h>
int d=0;
void out(int n, int k, int s[]){
	d++;
	printf("%d: ",d);
	for (int i=1;i<=k;i++){
		printf("%d ",s[i]);
	}
	printf("\n");
}
void Try(int i,int n,int k, int s[],int c[]){
	for (int j=1;j<=n;j++){
		if (c[j]==1){
			s[i]=j;
			c[j]=0;
			if (i==k) out(n,k,s);
			else Try(i+1,n,k,s,c);
			c[j]=1;
		}
	}
}
void Test(int c[],int n){
	for (int i=1;i<=n;i++)c[i]=1;
}
void TH(int n,int k,int s[],int c[]){
	Test(c,n);
	Try(1,n,k,s,c);
}
main(){
	int n,k;
	printf("\nNhap n: ");
	scanf("%d",&n);
	printf("\nNhap k: ");
	scanf("%d",&k);
	int s[n],c[n];
	TH(n,k,s,c);
}
