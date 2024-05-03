#include <bits/stdc++.h>
#define Max 10000 
using namespace std;
int target,m, S, F;
float c[101][101];
float d[101];
int Trance[101]; 
void input(int &target, int &m, int &S, int &F, float c[101][101]);
void khoitao(int &S, int &target, int Trance[101], float d[101], float c[101][101]);
void FordBellman(int &target, int Trance[101], float d[101], float c[101][101]);
void Print(int &F, int &S, int &target,int Trance[101], float d[101], float c[101][101]);

int main(){
	input(target, m, S, F, c);
	khoitao(S, target, Trance, d, c);
	FordBellman(target, Trance, d, c);
	Print(F, S, target, Trance, d, c); 
} 

void input(int &target, int &m, int &S, int &F, float c[101][101]){
	int u,v;
	float w; 
	cout << "So dinh: "; cin >> target;
    cout << "So canh: "; cin >> m;
    cout << "Dinh xuat phat: "; cin >> S;
    cout << "Dinh ket thuc: "; cin >> F;
	for(u=0;u<target;u++){
		for(v=0;v<target;v++){
			if(u==v) c[u][v]=0;
			else c[u][v]= Max;
		}
	}
	cout<<endl<<"Nhap trong so"<<endl;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		c[u][v]=w; c[v][u]=w; 
	}
}

void khoitao(int &S, int &target, int Trance[101], float d[101], float c[101][101]){
	for(int i=0;i<target;i++){
		d[i]=c[S][i];
		Trance[i]=S;
	}
}

void FordBellman(int &target, int Trance[101], float d[101], float c[101][101]){
	int Stop,Cout=0;
	do{
		Stop=1;
		for(int u=0;u<target;u++){ 
			for(int v=0;v<target;v++){
				if (d[v]>d[u]+c[u][v]){
					d[v]=d[u]+c[u][v];
					Trance[v]=u;
					Stop=0;
				}
			}
		}
		Cout++;
	}
	while (Stop == 1 ||(Cout >=target-2));
}

void Print(int &F, int &S, int &target,int Trance[101], float d[101], float c[101][101]){
	if(d[F]==Max) cout<<"Khong tim thay duong di";
	else {
		cout << "Khoang cach tu dinh " << S << " den dinh " << F << " la: " << d[F] << endl;
    	cout << "Duong di: ";
		while (F!=S) {
			cout << "(" << F << ") <- ";
			F= Trance[F];  
		} 
		cout<<S; 
	} 
} 
