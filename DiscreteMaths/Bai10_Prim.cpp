#include <stdio.h> 
#define max 1000 
 
int n,m, cout=0;
float c[101][101], d[101], W=0;
int Trance[101], Free[101], pa[101]; 
void input(int &n,int &m, float c[101][101]);
void init(int &n, int Free[101], int Trance[101], float d[101], float c[101][101], int pa[101]);
void PrintResult(float &W);
void Prim(int &n, int Free[101], int Trance[101], float d[101], float c[101][101], int pa[101], int cout, float &W);


int main(){
	input(n, m, c);
	init(n, Free, Trance, d, c, pa);
	PrintResult(W);
} 

void input(int &n,int &m, float c[101][101]){  
    int u, v;
	float w; 
	printf("So dinh:");scanf("%d",&n);
	printf("So canh:");scanf("%d",&m);
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

void init(int &n, int Free[101], int Trance[101], float d[101], float c[101][101], int pa[101]){
	for (int i=0;i<n;i++){
		d[i]=c[0][i];
		Free[i]=1;
		pa[i]=i; 
		Trance[i]=0; 
	} 
	    Free[0]=0; 
} 

void Prim(int &n, int Free[101], int Trance[101], float d[101], float c[101][101],int pa[101], int cout, float &W){ 
	float min = max; 
	int b=0; 
	for (int i=0;i<n;i++){
		if(Free[i] && pa[i]!=0 && d[i]<min){
			min=d[i];
			b=i;
		} 
	} 
	pa[b]=0;
	Free[b]=0;
	W+=d[b];
	printf("(%d,%d)=%.1f\n",Trance[b],b,d[b]);
	for(int i=0;i<n;i++){
		if(Free[i] && c[b][i]<d[i]){
			d[i]=c[b][i]; 
			Trance[i]=b; 
		} 
	} 
	
    if(cout!=n-2) {
    	Prim(n, Free, Trance, d, c, pa, cout+1, W);
	} 
}

void PrintResult(float &W){
	printf("Cay phu nho nhat la:\n");
	Prim(n, Free, Trance, d, c, pa, cout, W);
	printf("\n Gia cay phu nho nhat: %.1f",W);
}


