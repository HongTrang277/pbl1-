//Giair thích xem trên chương trình C bên trên
#include <bits/stdc++.h>
using namespace std;
 
void intput(int n, int m, int a[][100]);
void output(int n, int m, int a[][100]);
void tichMaTran(int a[][100], int b[][100], int m, int n, int m1);

int main()
{
    int n, m;
    cout<<"MA TRAN A:\nNhap so hang, so cot lan luot: ";
    cin>>n>>m;
    int a[100][100];
    cout<<"\n------Nhap phan tu ma tran A-----\n";
    intput(n, m, a);
     
    int n1, m1;
    cout<<"MA TRAN B:\nNhap so hang, so cot lan luot: ";
    cin>>n1>>m1;
    int b[100][100];
    cout<<"\n------Nhap phan tu ma tran B-----\n";
    intput(n1, m1, b);
 
     
    cout<<"\n------MA TRAN A-----\n";
    output(n,m,a);
    cout<<"\n------MA TRAN B-----\n";
    output(n,m,b);
     
    if(m == n1){
        tichMaTran(a,b,m,n,m1);
    }else{
        cout<<"So cot Ma tran A khac so hang ma tran B, khong the nhan 2 ma tran nay";
    }
    return 0;
}
void intput(int n, int m, int a[][100]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
}
void output(int n, int m, int a[][100]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) {
        cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
 
void tichMaTran(int a[][100], int b[][100], int m, int n, int m1){
    int c[100][100];
    int i, j, k;
     for(i=0;i<n;i++) 
        for(j=0;j<m1;j++) {
         int tt=0;
           for(k=0;k<m;k++)
               {
                 tt = tt + (a[i][k] * b[k][j]);
                }
            c[i][j] = tt;
    }
     
    cout<<"\nTICH 2 MA TRAN A B\n";
    output(n,m1,c);
}
 