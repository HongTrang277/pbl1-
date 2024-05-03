#include <bits/stdc++.h>
#include "PBLmatrix&file.hpp"
#include "PBLcalculation.hpp"
#include <string>

void doidong(float matrix[][MAX_SIZE], int n, int p, int q)
{ 
    float tmp;
    int k;
    if (p<=n && q<=n && p!=q)
    for (k=1; k<=n+1; k++) 
    {
        tmp = matrix[p][k];
        matrix[p][k] = matrix[q][k];
        matrix[q][k] = tmp;
    }
}

int main()
{
    int preChoice;
    float matrix[MAX_SIZE][MAX_SIZE];
    int size =-1 ;
    string file;
    cout << "Name the file that contains input matrix: ";
    getline(cin, file);
    switch (matrix_reader(file, matrix, size))
    {
        case 0:
        {
            cout << endl << "Unable to open file/file doesn't exist in the same folder" << endl;
            break;
        }
        case 1:
        {
            cout << endl << "Not a square matrix" << endl;
            break;
        }
        case 2:
        {
            cout << endl << "Read matrix from file \"" << file << "\" succeed" << endl;
            break;
        }
    }
    printMatrix(matrix,size);
    cout << "Matrix after" << endl;
    TurnIntoTriangleMatrix(matrix, preChoice);
    printMatrix(matrix,size);
    return 0;
}