#include <bits/stdc++.h>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"
int main()
{
    int i;
    int size,size1,size2;

	string fileName;

    float matrix[MAX_SIZE][MAX_SIZE];
	float valid_matrix[MAX_SIZE][MAX_SIZE];
    valid_matrix[0][0]=(float)TRASHVALUE;
	float triangle_matrix[MAX_SIZE][MAX_SIZE];
    triangle_matrix[0][0]=(float)TRASHVALUE;
    float resVector[MAX_SIZE];
    resVector[0]=(float)TRASHVALUE;
    double Qx;
	
    POLYNOMIAL poly = new polynomial;
    zero_polynomial(poly);

    int userChoice;
    int nextstep, preChoice= -1;

    fileName = "testMatrix.txt";
    matrix_reader(fileName, matrix, size);
    SavedValidMatrices(matrix,size,valid_matrix,size1);
    TurnIntoTriangleMatrix(valid_matrix,size1, triangle_matrix, size2);
    SolveTriangleMatrix(triangle_matrix, size2,resVector);
    printMatrix(triangle_matrix,size2);

    zero_polynomial(poly);
            for (i =0; i<size1; i++)
                for (int j=0; j<=size1; j++)
                    poly->coeff_array[j]+=matrix[i][j];
            cout <<"Polynomial:"<<endl;
            display_polynomial(poly,size1); 

    savepoly_resToFile(poly , resVector, size, "result.txt", preChoice);
    return 0;
}