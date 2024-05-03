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

unsigned int Max(unsigned int a, unsigned int b)
{
    return a>b?a:b;
}

void display_polynomial(POLYNOMIAL poly)
{
    for(int i=0; i<= poly->high_power; i++ ) {
        if(poly->coeff_array[i]!=0){
            if(poly->coeff_array[i] >0 && i!=0)
                cout<<" + ";
            else if(poly->coeff_array[i]<0)
                cout<<" - ";
            if(abs(poly->coeff_array[i])!=1)
                cout<<abs(poly->coeff_array[i]);
            if ( abs(poly->coeff_array[i])==1  && i== poly->high_power)
                cout<<abs(poly->coeff_array[i]);
            if(abs(poly->coeff_array[i])>0 && i< poly->high_power){
                cout<<"x";
                if(i< poly->high_power-1) cout<<"^"<<poly->high_power - i;
            }
        }
    }
    cout<<endl;
}

void SUM(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_sum)
{
    zero_polynomial(poly_sum);
    poly_sum->high_power = Max(poly1->high_power, poly2->high_power);
    for (int i=0; i<= poly_sum->high_power; i++)
    {
        poly_sum->coeff_array[i]=poly1->coeff_array[i] +poly2->coeff_array[i];

    }
}

void mult_polynomial (POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_prod)
{
  zero_polynomial(poly_prod);
  poly_prod->high_power = poly1->high_power + poly2->high_power;

  for (int i = 0; i <= poly1->high_power; i++) {
    for (int j = 0; j <= poly2->high_power; j++) {
      int coeff = poly1->coeff_array[i] * poly2->coeff_array[j];
      poly_prod->coeff_array[i + j] += coeff;
    }
  }
}

void input_polynomial(POLYNOMIAL poly)
{
    zero_polynomial(poly);
    cout << "Input high power :";
    cin >> poly->high_power;
    for (int i=0; i <= poly->high_power; i++)
    {
        cout << "Input expo " << poly->high_power -i << "coeff: ";
        cin >> poly->coeff_array[i];
        cout << endl; 
    }
}


int main()
{
    POLYNOMIAL poly1 = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly2 = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly_sum = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    POLYNOMIAL poly_prod = (POLYNOMIAL)malloc(sizeof(struct polynomial));
    zero_polynomial(poly1);zero_polynomial(poly2);
    poly1->high_power =3;
    poly1->coeff_array[0]= -7;
    poly1->coeff_array[1]= 0;
    poly1->coeff_array[2]= 4;
    poly1->coeff_array[3]= 10;

    input_polynomial(poly2);

    display_polynomial(poly1);
    display_polynomial(poly2);
    SUM(poly1, poly2, poly_sum);
    mult_polynomial(poly1, poly2, poly_prod);
    cout << "SUM:";
    display_polynomial(poly_sum);
    cout << "multi: ";
    display_polynomial(poly_prod);
    free(poly1);free(poly2);
    free(poly_prod);
    free(poly_sum);
    return 0;
}