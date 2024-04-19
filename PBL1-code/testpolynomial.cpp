#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
#define MAX_DEGREE 100
typedef struct polynomial
{
    unsigned int high_power; // số nguyên không dấu, bậc cao nhất của đa thức
    int coeff_array[MAX_DEGREE+1]; // mảng lưu các hệ số của thành phần đa thức
} *POLYNOMIAL;

void zero_polynomial ( POLYNOMIAL poly) // cho tất cả các hệ số và bậc cao nhất =0
{
    for (int i =0; i <= MAX_DEGREE; i++)
        poly->coeff_array[i] =0;
    poly->high_power = 0;
}

void display_polynomial(POLYNOMIAL poly)
{
    for(int i=0; i<=3; i++ ) {
        if(poly->coeff_array[i]!=0){
            if(poly->coeff_array[i] >0 && i!=0)
                cout<<" + ";
            else if(poly->coeff_array[i]<0)
                cout<<" - ";
            if(abs(poly->coeff_array[i])!=1)
                cout<<abs(poly->coeff_array[i]);
            if(abs(poly->coeff_array[i])>0 && i<3){
                cout<<"x";
                if(i<2) cout<<"^"<<3 -i;
            }
        }
    }
    cout<<endl;
}

int main()
{
    POLYNOMIAL poly1 = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly2 = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly_sum = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly_prod = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    zero_polynomial(poly1);zero_polynomial(poly2);
    poly1->high_power =3;
    poly1->coeff_array[0]= 7;
    poly1->coeff_array[1]= 0;
    poly1->coeff_array[2]= 4;
    poly1->coeff_array[3]= 10;

    poly2->high_power =3;
    poly2->coeff_array[0]= 5;
    poly2->coeff_array[1]= -3;
    poly2->coeff_array[2]= 5;

    display_polynomial(poly1);
    display_polynomial(poly2);
    return 0;
}