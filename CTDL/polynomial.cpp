#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
#define MAX_DEGREE 100
typedef struct polynomial
{
    unsigned int high_power;
    int coeff_array[MAX_DEGREE+1];
} *POLYNOMIAL;

void zero_polynomial ( POLYNOMIAL poly)
{
    for (int i =0; i <= MAX_DEGREE; i++)
        poly->coeff_array[i] =0;
    poly->high_power = 0;
}

unsigned int Max(unsigned int a, unsigned int b)
{
    return a>b?a:b;
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
void display_polynomial(POLYNOMIAL poly)
{
    for (int i = poly->high_power; i >=0; i--)
    {
        if (poly->coeff_array[i]==0)
            continue;
        if (poly->coeff_array[i]>0)
        {
            if (i!= poly->high_power) 
            {
                cout << " + ";
            }
        }
        else
        {   if (i!= poly->high_power)
                cout << " - ";
            else 
                cout << "-";
        }
        if (abs(poly->coeff_array[i] )!=1)
            cout << abs(poly->coeff_array[i]);
        if (i!=0)
            cout<< "x";
        if (i > 1)
            cout << "^" << i;
    }
    cout << endl;
}

void mult_polynomial (POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_prod)
{
    zero_polynomial(poly_prod);
    poly_prod->high_power = poly1->high_power + poly2->high_power;
    for (int i = 0; i<= poly1->high_power;i++)
        for(int j=0; j<= poly2->high_power; j++)
        {
            poly_prod->coeff_array[i+j] = poly1->coeff_array[i]*poly2->coeff_array[j];
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
    SUM(poly1, poly2, poly_sum);
    mult_polynomial(poly1, poly2, poly_prod);
    cout << "SUM:";
    display_polynomial(poly_sum);
    cout << "multi: ";
    display_polynomial(poly_prod);
    return 0;
}