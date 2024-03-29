#include <stdio.h>
void out(int n, int k, int s[]){
	for (int i=1;i<=k;i++){
		printf("%d ",s[i]);
	}
	printf("\n");
}
void Try(int i,int n,int k, int s[]){
	for (int j=1;j<=n;j++){
		if (j>=s[i-1]+1&&j<=n-k+i){
			s[i]=j;
			if (i==k){out(n,k,s);
			}
			else Try(i+1,n,k,s);
		}
	}
}
void TH(int n,int k,int s[]){
	if(k>=0&&k<=n)s[0]=0;
	Try(1,n,k,s);
}
main(){
	int n,k;
	printf("\nNhap n: ");
	scanf("%d",&n);
	printf("\nNhap k: ");
	scanf("%d",&k);
	int s[n];
	TH(n,k,s);
}
