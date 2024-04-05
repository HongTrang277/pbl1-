#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct Node {
    int coeff;
    int expo;
    struct Node *next;
};

typedef struct Node *POLYNOMIAL;
typedef struct Node *Position;

POLYNOMIAL createPolynomial(){
    POLYNOMIAL headerNode = (POLYNOMIAL)malloc(sizeof(struct Node));
    headerNode->next = NULL;
    headerNode->expo = INT_MAX;    
    return headerNode;
}

void Add_polynomial( POLYNOMIAL poly, int coeff, int expo)
{
    Position prev = poly;
    while (poly != NULL && poly->expo >= expo)
    {
        prev = poly;
        poly = poly->next;
    }

    if (prev->expo == expo)
        prev->coeff += coeff;
    else 
    {
        Position newItem = (Position) malloc(sizeof(struct Node));
        newItem->coeff = coeff; newItem->expo = expo;

        newItem->next = prev->next;
        prev->next = newItem;
    }
}

void sum_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_sum)
{
    poly1= poly1->next;
    poly2= poly2->next;
    while (poly1 != NULL)
    {
        Add_polynomial(poly_sum, poly1->coeff, poly1->expo);
        poly1= poly1->next;
    }

    while (poly2 != NULL)
    {
        Add_polynomial(poly_sum, poly2->coeff , poly2->expo);
        poly2 = poly2->next;
    }

}

void Mult_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_prod)
{
    poly1 = poly1->next;
    poly2 = poly2->next;
    POLYNOMIAL temp;
    while (poly1 != NULL)
    {
        temp = poly2;
        while (poly2 != NULL)
        {
            Add_polynomial(poly_prod, poly1->coeff*poly2->coeff , poly1->expo + poly2->expo);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
        poly2 = temp;
    }
}
void display(POLYNOMIAL poly)
    {
        poly = poly->next;
        while (poly != NULL)
        {
            if (poly->coeff != 0 )
                cout << poly->coeff << "^" << poly->expo << " ";
            poly = poly->next; 
        }
        cout << endl;        
    }
int main()
{
    POLYNOMIAL poly1 = createPolynomial();
    POLYNOMIAL poly2 = createPolynomial();
    POLYNOMIAL poly_sum = createPolynomial();
    POLYNOMIAL poly_prod = createPolynomial();

    Add_polynomial(poly1, 5,5); Add_polynomial(poly1, 3,4);
    Add_polynomial(poly1, -6,2);Add_polynomial(poly1, 3,0);
    Add_polynomial(poly1, 10,3);
    
    Add_polynomial(poly2, 5,5); Add_polynomial(poly2, 3,4);
    Add_polynomial(poly2, 10,3);

    display(poly1);

    display(poly2);

    sum_polynomial(poly1, poly2, poly_sum);
    Mult_polynomial(poly1, poly2, poly_prod);

    cout << endl << "SUM: ";
    display(poly_sum);
    cout << endl << "MULT: ";
    display(poly_prod);

    return 0;
}