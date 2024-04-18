#include <bits/stdc++.h>
#include "PBLconsole.hpp"
#include <string>

using namespace std;

int main()
{
    float matrix[MAX_SIZE][MAX_SIZE];
    int size =-1 ;
    string file = "size4.txt";
    cout << matrix_reader(file,matrix, size);
    printMatrix(matrix,size);
    return 0;
}