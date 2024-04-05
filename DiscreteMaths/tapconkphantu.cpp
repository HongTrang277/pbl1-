#include <stdio.h>
//tap con k phan tu cua tap n phan tu
//to hop khong lap chap k cua n
//pp sinh
int n,stop;
void Init(int a[],int k){
	int i;
	for (i=1;i<=k;i++)a[i]=i;
}
void Out(int a[],int k){
	int i;
	printf("\n");
	for (i=1;i<=k;i++) printf("%d ",a[i]);
}
int last(int a[],int k){
	int i;
	for (i=k;i>=1;i--) if (a[i]!=n-k+i) return 0;
	return 1;//la phan tu cuoi
}
void next(int a[],int k){
	int i=k;
	while(i>=1 && a[i]==n-k+i)i--;
	a[i]++;
	int j;
	for (j=i+1;j<=k;j++) a[j]=a[i]+j-i;
}
void tao(int a[],int k){
	Init(a,k); Out(a,k);
	stop=last(a,k);
	while(stop==0){
		next(a,k);
		Out(a,k);
		stop=last(a,k);
	}
}
main(){
	int k;
	printf("\nnhap n: ");
	scanf("%d",&n);
	printf("\nnhap k: ");
	scanf("%d", &k);
	if (k==0){printf("\ntap rong");
	}
	else{
	int a[k];
	tao(a,k);}
}
