#include <bits/stdc++.h>
using namespace std;

#define MAX 20

bool Ok(int x2, int y2 , int a[MAX]) {
    // Kiểm tra cách đặt có thỏa mãn không
    for (int i = 1; i < x2; i++) {
        if (a[i] == y2 || abs(i - x2) == abs(a[i] - y2)) {
            return false;
        }
    }
    return true;
}

void Xuat(int n, int a[MAX]) 
{
    // In ra một kết quả
    for (int i = 1; i <= n; i++) 
    {
        cout << " " << (char)(64+a[i]) << i;
    }
    cout << endl;
}

void Try(int i, int n, int a[MAX]) {
    for (int j = 1; j <= n; j++) {
        // Thử đặt quân hậu vào các cột từ 1 đến n ( Ứng với A - 'A+n-1')
        if (Ok(i, j ,a)) {
            // Nếu cách đặt này thỏa mãn thì lưu lại vị trí
            a[i] = j;
            // Nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
            if (i == n) {
                Xuat(n,a);
            }
            Try(i + 1, n, a);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[MAX];
    Try(1, n, a);
    return 0;
}
