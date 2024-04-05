#include <stdio.h>
#include <vector>
#include<algorithm>
using namespace std;


struct Canh{
    int d1, d2, trongso;
};

const int maxn = 1000000;
int n, m;
int goc[maxn], sz[maxn];

vector<Canh> CANH;

void tao(){
	int i;
    for(i = 1; i <= n; i++){
        goc[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == goc[v]) return v;
    return goc[v] = find(goc[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false; 
    if(sz[a] < sz[b]) swap(a, b);
    goc[b] = a;
    sz[a] += sz[b];
    return true;
}

void Input(){
    printf("Nhap so dinh va so canh cua do thi: ");
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y, w;
        printf("Nhap hai dinh va trong so canh thu %d: ", i+1);
        scanf("%d%d%d", &x, &y, &w);
        Canh e;
        e.d1 = x; e.d2 = y; e.trongso = w;
        CANH.push_back(e);
    }
}

bool sapxeptrongso(Canh a, Canh b){
    return a.trongso < b.trongso;
}

void kruskal(){
    vector<Canh> mst;
    int d = 0;
    sort(CANH.begin(), CANH.end(), sapxeptrongso);
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        Canh e = CANH[i]; 
        if(Union(e.d1, e.d2)){
            mst.push_back(e);
            d += e.trongso;
        }
    }
    
    if(mst.size() != n - 1){
        printf("Do thi khong lien thong!\n");
    }
    else{
        printf("Cay toi dai ngan nhat: d = %d\n", d);
        for(auto it : mst){
            printf("(%d;%d) = %d\n", it.d1, it.d2, it.trongso);
        }
    }
}

int main(){
    Input();
    tao();
    kruskal();
}
