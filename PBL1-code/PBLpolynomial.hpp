#include<bits/stdc++.h>
#include<fstream>

#define MAX_SIZE 100
using namespace std;

typedef struct polynomial {
    unsigned int high_power; //high_power=size
    int coeff_array [MAX_SIZE]; // vector nghiệm nè ae, cấp tối đa là mũ 99 thôi được rồi
} *POLYNOMIAL;


void SumOfCols(float matrix[][MAX_SIZE],POLYNOMIAL poly, int &size) {
    int* coeff_ptr = poly->coeff_array;
    for(int i=0; i<=size; i++){
         coeff_ptr[i]=0;
        for (int j = 0; j <=size+1; j++) {
            coeff_ptr[j] += matrix[i][j];
        }
    }
}

void zero_polynomial ( POLYNOMIAL poly) // cho tất cả các hệ số và bậc cao nhất =0
{
    for (int i =0; i <= MAX_SIZE; i++)
        poly->coeff_array[i] =0;
    poly->high_power = 0;
}

void display_polynomial(POLYNOMIAL poly, int &size)  
{
    poly->high_power=size;
    for(int i=0; i<=size; i++ ) {
        if(poly->coeff_array[i]!=0){
            if(poly->coeff_array[i] >0 && i!=0)
                cout<<" + ";
            else if(poly->coeff_array[i]<0)
                cout<<" - ";
            if(abs(poly->coeff_array[i])!=1)
                cout<<abs(poly->coeff_array[i]);
            if(abs(poly->coeff_array[i])>0 && i<size){
                cout<<"x";
                if(i<size-1) cout<<"^"<<size -i;
            }
        }
    }
}