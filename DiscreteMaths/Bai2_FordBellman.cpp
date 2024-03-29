#include <stdio.h>
#define Max 10000 

int n,m, S, F;
float c[101][101];
float d[101];
int Trance[101]; 
void input(int &n, int &m, int &S, int &F, float c[101][101]);
void init(int &S, int &n, int Trance[101], float d[101], float c[101][101]);
void FordBellman(int &n, int Trance[101], float d[101], float c[101][101]);
void PrintResult(int &F, int &S, int &n,int Trance[101], float d[101], float c[101][101]);

int main(){
	input(n, m, S, F, c);
	init(S, n, Trance, d, c);
	FordBellman(n, Trance, d, c);
	PrintResult(F, S, n, Trance, d, c); 
} 

void input(int &n, int &m, int &S, int &F, float c[101][101]){
	int u,v;
	float w; 
	printf("So dinh:");scanf("%d",&n);
	printf("So canh:");scanf("%d",&m);
	printf("Dinh xuat phat:");scanf("%d",&S);
	printf("Dinh ket thuc:");scanf("%d",&F); 
	for(u=0;u<n;u++){
		for(v=0;v<n;v++){
			if(u==v) c[u][v]=0;
			else c[u][v]= Max;
		}
	}
	printf("\n Nhap trong so:\n");
	for(int i=0;i<m;i++){
		scanf("%d %d %f",&u,&v,&w);
		c[u][v]=w; c[v][u]=w; 
	}
}

void init(int &S, int &n, int Trance[101], float d[101], float c[101][101]){
	for(int i=0;i<n;i++){
		d[i]=c[S][i];
		Trance[i]=S;
	}
}

void FordBellman(int &n, int Trance[101], float d[101], float c[101][101]){
	int Stop,Cout=0;
	do{
		Stop=1;
		for(int u=0;u<n;u++){ 
			for(int v=0;v<n;v++){
				if (d[v]>d[u]+c[u][v]){
					d[v]=d[u]+c[u][v];
					Trance[v]=u;
					Stop=0;
				}
			}
		}
		Cout++;
	}
	while (Stop == 1 ||(Cout >=n-2));
}

void PrintResult(int &F, int &S, int &n,int Trance[101], float d[101], float c[101][101]){
	if(d[F]==Max) printf("Khong tim thay duong di");
	else {
		printf("Khoang cach tu dinh %d den dinh %d la: %.1f\n",S,F,d[F]);
		printf("Duong di: ");
		while (F!=S) {
			printf("(%d) <- ",F);
			F= Trance[F];  
		} 
		printf("%d",S); 
	} 
} 
