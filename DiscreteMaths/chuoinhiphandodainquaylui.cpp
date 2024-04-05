#include <stdio.h>
int n,count=1;
void out(char b[]){
	printf("\n%d:\t",count);
	int i;count++;
	for (i=1;i<=n;i++)putchar(b[i]);
}
void Try(int i,char b[]){
	char j;
	for (j='0';j<='1';j++){
		b[i]=j;
		if (i==n)out(b);
		else Try(i+1,b);
	}
}
int main(){
	printf("\nnhap n: ");
	scanf("%d", &n);
	char b[n];
	Try(1,b);
}
