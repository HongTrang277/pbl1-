// Viết bài tập 1 bằng menu
#include<bits/stdc++.h>
using namespace std ;
#define MAX 100
int i, n=0;
void menu(int n){
    cout <<"Hãy chọn menu sau"<<endl;
    cout << "1. Đọc dữ liệu từ bàn phím"<<endl;
    cout << "2. Đọc dữ liệu từ file" <<endl;
    cout << "3. Tìm ma trận tổng và tích" <<endl;
    cout << "4. Tìm ma trận chuyển vị của ma trận A" <<endl;
    cout << "5. Lưu kết quả vào file"<<endl;
    cout << "6. Kết thúc" <<endl;
    cout<<"tổng số mục bạn muốn chọn:"; cin>>n;
    int a[MAX];
    int choice=0;
    for(int i=1; i<=n;i++) {
        cout<<"mục số "<<i<<":";
        cin >>choice;
        a[i]=choice;
        choice=0;
    }
    cout <<"Bạn đã chọn";
    for(int i=1; i<=n;i++){
        switch(a[i]) {
            case 1: cout<<" đọc dữ liệu từ bàn phím ";
            case 2: cout<<" đọc dữ liệu từ file "; break;
            case 3: cout<<" tìm ma trận tổng và tích "; break;
            case 4: cout<<" tìm ma trận chuyển vị của ma trận A "; break;
            case 5: cout<<" lưu kết quả vào file "; break;
            case 6: cout<<" kết thúc"; break;
        }
        if(i==n) break;
        else {cout<<"và";}
    }
}
int main() {
    menu(n);
    return 0;
}