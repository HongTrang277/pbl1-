# include <stdio.h>
# include "conio.h"
# include "math.h"
# define max 10
/* Ham nhap mang a(n,n+1)*/
void nhapmt(float a[][max], int n)
{ int i,j; float x;
for (i=1; i<=n; i++)
for (j=1; j<=n+1; j++)
{ printf(" pt[%d%d] = ", i, j);
scanf("%f",&x); a[i][j] = x;
}
}
/* Ham xuat mang a(n,n+1)*/
void xuatmt(float a[][max], int n)
{ int i, j;
for (i=1;i<=n; i++)
{ printf("\n");
for (j=1;j<=n+1;j++) printf("%8.3f ", a[i][j]);
}
}

void hoandoi(float *a, float *b)
{ float t;
t = *a; *a = *b; *b = t;
}

void doidong(float a[][max], int n, int p, int q)
{ int k;
 if (p<=n && q<=n && p!=q)
 for (k=1; k<=n+1; k++) hoandoi(&a[p][k], &a[q][k]);
}

int main()
{ 
    float a[max][max];
    float x[max], m, s;
    char tt; int n, i, j, k;
    while (1) 
    { 
        printf("\n\n Nhap n = "); scanf("%d", &n);
        printf("\n\n Nhap he so cua he phuong trinh:\n"); nhapmt(a, n);
        printf("\n\n He phtrinh da cho: "); xuatmt(a, n);
    /* bien doi A ve ma tran tam giac tren */
        for(i=1; i<n; i++)
        { 
            if (a[i][i]==0)
            { 
                for (k=2; k<=n; k++)
                if (a[k][i]!=0) break;
                doidong(a, n, i, k);
                if (k>n) return 0; 
            }
        
        for(j=i+1; j<=n; j++)
        { m = -a[j][i]/a[i][i];
        for (k=i; k<=n+1; k++) a[j][k]+=a[i][k]*m;
        }
        }
        printf("\n\n He phtrinh sau khi bien doi:"); xuatmt(a, n);
        /* tim nghiem theo qua trinh nguoc */
        for(i=n; i>=1; i--)
        { s=a[i][n+1];
        for (k=i+1; k<=n; k++) s-=a[i][k]*x[k];
        if (a[i][i]!=0) x[i] = s/a[i][i];
        }
        printf("\n\n Nghiem he phtrinh: ");
        for(i=1; i<=n; i++) printf("%.3f ", x[i]);
        printf("\n\n Ban tiep tuc ko(c/k)? ");
        tt = getch();
        if (tt!='c') break;
    }
    return 0;
}