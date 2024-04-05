#include <stdio.h> 
#define max 1000 
 
int n,m,S,F;
float c[101][101];
float d[101];
int Trance[101], Free[101]; 

void input(int &n,int &m,int &S, int &F, float c[101][101]){  
    int u, v;
	float w; 
	printf("So dinh:");scanf("%d",&n);
	printf("So canh:");scanf("%d",&m);
	printf("Dinh xuat phat:");scanf("%d",&S);
	printf("Dinh ket thuc:");scanf("%d",&F); 
	for(u=0;u<n;u++){
		for(v=0;v<n;v++){
			if(u==v) c[u][v]=0;
			else c[u][v]= max;
		}
	}
	printf("\n Nhap trong so (khong am):\n");
	for(int i=0;i<m;i++){
		scanf("%d %d %f",&u,&v,&w);
		c[u][v]=w; c[v][u]=w;
	} 
}

void init(int &S, int &n, int Trance[101], int Free[101], float d[101], float c[101][101]){
	for (int i=0;i<n;i++){
		d[i]=c[S][i];
		Free[i]=1; 
		Trance[i]=S; 
	} 
	    Free[S]=0; 
} 

void dijsktra(int &F,int &n, int Trance[101], int Free[101], float d[101], float c[101][101]){ 
	float min = max; 
	int b; 
	for (int i=0;i<n;i++){
		if(Free[i] && d[i]<min){
			min=d[i];
			b=i;
		} 
	} 
	Free[b]=0;
	for (int i=0;i<n;i++){
	    if(Free[i] && d[b]+c[b][i]<d[i]){
		Trance[i]=b;
		d[i]=d[b]+c[b][i]; 
	    }
    }
    
    if(b!=F){
    	dijsktra(F,n, Trance, Free, d, c);
	} 
}

void PrintResult(int &F, int &S, int Trance[101], float d[101]){
	if(d[F]==max) printf("Khong tim thay duong di");
	else {
		printf("\nKhoang cach tu dinh %d den dinh %d la: %.1f\n",S,F, d[F]);
	    printf("Duong di: ");
		while (F!=S) {
			printf("(%d) <- ",F);
			F= Trance[F]; 
		} 
		printf("%d",S); 
	} 
} 
int main(){
	input(n, m, S, F, c);
	init(S, n, Trance, Free, d, c);
	dijsktra(F, n, Trance, Free, d, c);
	PrintResult(F, S, Trance, d); 
} 

