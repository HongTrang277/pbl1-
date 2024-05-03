#include <bits/stdc++.h>

using namespace std;
#define MAX 10000 

int n,m, S, F;
float c[101][101];
float d[101];
int Trance[101]; 
void input(int n, int m, int S, int F, float c[101][101]);
void init(int S, int n, int Trance[101], float d[101], float c[101][101]);
void BellmanFord(int n, int Trance[101], float d[101], float c[101][101]);
void PrintResult(int F, int S, int n,int Trance[101], float d[101], float c[101][101]);

int main(){
	input(n, m, S, F, c);
	init(S, n, Trance, d, c);
	BellmanFord(n, Trance, d, c);
	PrintResult(F, S, n, Trance, d, c); 
} 

void input(int n, int m, int S, int F, float c[101][101]){
	int u,v;
	float w; 
	cout << "So dinh:";
	cin >> n; cout << endl;
	cout << "So canh:";
	cin >> m; cout << endl;
	cout << "Dinh xuat phat:"; 
	cin >> S; cout << endl;
	cout << "Dinh ket thuc:";
	cin >> F; cout << endl;
	for(u=0;u<n;u++){
		for(v=0;v<n;v++){
			if(u==v) c[u][v]=0;
			else c[u][v]= MAX;
		}
	}
	cout << "Nhap trong so:" << endl;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		c[u][v]=w; c[v][u]=w; 
	}
}

void init(int S, int n, int Trance[101], float d[101], float c[101][101]){
	for(int i=0;i<n;i++){
		d[i]=c[S][i];
		Trance[i]=S;
	}
}

void BellmanFord(int n, int Trance[101], float d[101], float c[101][101]){
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

void PrintResult(int F, int S, int n,int Trance[101], float d[101], float c[101][101]){
	if(d[F]==MAX) printf("Khong tim thay duong di");
	else {
		cout << "Khoang cach tu dinh " << S << " den dinh " << F << " la:" << setprecision(1) << d[F];
		cout << "Duong di: ";
		while (F!=S) {
			cout << "("<< F <<") <- ";
			F= Trance[F];  
		} 
		cout << S; 
	} 
} 
