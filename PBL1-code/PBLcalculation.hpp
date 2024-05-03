#include <bits/stdc++.h>
#include <fstream>

#define MAX_SIZE 100
#define TRASHVALUE 12345.6789

using namespace std;

int TurnIntoTriangleMatrix(float matrix[][MAX_SIZE], int &preChoice);
void PermuteRow(float matrix[][MAX_SIZE], int size, int row1, int row2);
// int CalculateQ();

int TurnIntoTriangleMatrix(float matrix[][MAX_SIZE] , int &preChoice)
{
    int i,j,k;
    float m;
    int size;
    for(i=1; i<size; i++)
    { 
        if (matrix[i][i]==0)
        { 
            for (k=2; k<=size; k++)
            {
                if (matrix[k][i]!=0) 
                    break;
            }
            PermuteRow(matrix, size, i, k);
            if (k>size) 
                return 0; // Case ?
        }
    
        for(j=i+1; j<=size; j++)
        { 
            m = -matrix[j][i]/matrix[i][i];
            for (k=i; k<=size+1; k++) 
                matrix[j][k]+=matrix[i][k]*m;
        }
    }
    return 0;
}

void SolveTriangleMatrix(float matrix[][MAX_SIZE], int size, float resVector[MAX_SIZE])
{
    int i,k;
    float sub;
    for(i=size; i>=1; i--)
        { 
            sub=matrix[i][size+1];
            for (k=i+1; k<=size; k++) sub-=matrix[i][k]*resVector[k];
            if (matrix[i][i]!=0) resVector[i] = sub/matrix[i][i];
        }
}

void PermuteRow(float matrix[][MAX_SIZE], int size, int row1, int row2)
{
    int iARow, iACol;
    int tmp;
 
    if (row1 < 0 || row1 >= size ||
        row2 < 0 || row2 >= size ||
        row1 == row2)
    {
        return;
    }
 
    // Duyệt theo cột
    for (iACol = 0; iACol < size +1 ; iACol++)
    {
        tmp = matrix[row1][iACol];
        matrix[row1][iACol] = matrix[row2][iACol];
        matrix[row2][iACol] = tmp;
    }
}