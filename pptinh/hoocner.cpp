#include <bits/stdc++.h>
using namespace std;

void nhapHeSo(float a[], int n) {
    for (int i = 0; i <= n; i++) {
        cout << "Hệ số thứ " << i + 1 << " = ";
        cin >> a[i];
    }
}

void tinhHeSoMoi(float a[], int n, float c) {
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            a[j] = a[j - 1] * c + a[j];
}

void inHeSo(float a[], int n, float c) {
    cout << "Các hệ số của p(y + " << fixed << c << ") lần lượt là:\n";
    for (int i = 0; i <= n; i++) {
        cout << "Hệ số bậc " << n - i << " = " << fixed << a[i] << "\n";
    }
}

int main() {
    int n;
    float c, a[10];
    
    cout << "Nhập giá trị c cho trước: ";
    cin >> c;
    cout << "Nhập bậc giá trị đa thức: ";
    cin >> n;
    cout << "Nhập các hệ số: \n";
    
    nhapHeSo(a, n);
    tinhHeSoMoi(a, n, c);
    inHeSo(a, n, c);

    return 0;
}
