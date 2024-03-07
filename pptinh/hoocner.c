#include <stdio.h>

void nhapHeSo(float a[], int n) {
    for (int i = 0; i <= n; i++) {
        printf("Hệ số thứ %d = ", i + 1);
        scanf("%f", &a[i]);
    }
}

void tinhHeSoMoi(float a[], int n, float c) {
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            a[j] = a[j - 1] * c + a[j];
}

void inHeSo(float a[], int n, float c) 
{
    printf("Các hệ số của p(y + %.2f) lần lượt là:\n", c);
    for (int i = 0; i <= n; i++) 
    {
        printf("Hệ số bậc %d = %.2f\n", n - i, a[i]);
    }
}

int main() {
    int n;
    float c, a[10];
    
    printf("Nhập giá trị c cho trước: ");
    scanf("%f", &c);
    printf("Nhập bậc giá trị đa thức: ");
    scanf("%d", &n);
    printf("Nhập các hệ số: \n");
    
    nhapHeSo(a, n);
    tinhHeSoMoi(a, n, c);
    inHeSo(a, n, c);

    return 0;
}
