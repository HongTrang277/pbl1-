#include <stdio.h>
int x[100], used[100],n,k,c=0;


void print2(){
	printf ("%d: ", ++c);
	for(int i=1;i<=k;i++)
		printf ("%d", x[i]);
	printf ("\n");
}

void Try2(int i){// chinh hop
	for(int j=1; j<=n; j++){
		if(used[j]==0){
			x[i]= j;
			used[j] = 1;
			if(i==k) print2();
			else Try2(i+1);
			used[j]=0;
		}
	}
}
// chinh hop lap
void Try3(int i){
	for(int j=1; j<=n ;j++){
		x[i] =j;
		if (i==k) print2();
		else Try3(i+1);
	}
}

int main(){
	printf("\nNhap n: ");
	scanf ("%d", &n);
	printf("\nNhap k: ");
	scanf ("%d", &k);
	printf("\nchinh hop: \n");
	Try2(1);
	printf("\nchinh hop lap: \n");
	Try3(1);
}
