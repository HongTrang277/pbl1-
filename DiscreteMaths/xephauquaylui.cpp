#include <stdio.h>
int a[100],b[100],c[100],x[100];
int count;
int Init(int n){
	int i;
	for (i=1;i<=n;i++)a[i]=1;
	for (i=2;i<=2*n;i++)b[i]=1;
	for (i=1-n;i<=n-1;i++)c[i]=1;
}
int out(int n){
	for (int i=1;i<=n;i++) printf("%3d",x[i]);
	printf("\n");
}
int Try(int i,int n){
	for (int j=1;j<=n;j++){
		if (a[j]&&b[i+j]&&c[i-j]){
			x[i]=j;
			a[j]=0;
			b[i+j]=0;
			c[i-j]=0;
			if (i==n) {out(i);count++;
			}
			else Try(i+1,n);
			a[j]=1;
			b[i+j]=1;
			c[i-j]=1;
		}
	}
}
int main(){
	int n;
	printf("\nNhap n hau: ");
	scanf("%d",&n);
	Init(n);
	Try(1,n);
	printf("%d ",count); //so cach xep
}
