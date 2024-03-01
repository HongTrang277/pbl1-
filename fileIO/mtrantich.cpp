#include <bits/stdc++.h>
using namespace std;

void input(int n, int m, int a[][100]);
void output(int n, int m, int a[][100]);
void tichMaTran(int a[][100], int b[][100], int m, int n, int m1);
void swapRow(int a[][100], int aRow, int aCol, int row1, int row2);

int main()
{
    int n, m;
    cout<<"MA TRAN A:\nNhap so hang, so cot lan luot: ";
    cin>>n>>m;
    int a[100][100];
    cout<<"\n------Nhap phan tu ma tran A-----\n";
    input(n, m, a);
     
    int n1, m1;
    cout<<"MA TRAN B:\nNhap so hang, so cot lan luot: ";
    cin>>n1>>m1;
    int b[100][100];
    cout<<"\n------Nhap phan tu ma tran B-----\n";
    input(n1, m1, b);
 
     
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
void input(int n, int m, int a[][100]){
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

void swapRow(int a[][100], int aRow, int aCol, int row1, int row2)
{
    int iaRow, iaCol;
    int tmp;
 
    if (row1 < 0 || row1 >= aRow ||
        row2 < 0 || row2 >= aRow ||
        row1 == row2)
    {
        return;
    }
 
    for (iaCol = 0; iaCol < aCol; iaCol++)
    {
        tmp = a[row1][iaCol];
        a[row1][iaCol] = a[row2][iaCol];
        a[row2][iaCol] = tmp;
    }
}