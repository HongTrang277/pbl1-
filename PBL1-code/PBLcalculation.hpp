#include <bits/stdc++.h>
#include <fstream>
#include <math.h>
#include <string>
#include <Windows.h>

#define MAX_SIZE 100
using namespace std;

typedef struct polynomial
{
    unsigned int high_power;
    int coeff_array[MAX_SIZE];
} *POLYNOMIAL;

void SumOfCols(float matrix[][MAX_SIZE], POLYNOMIAL poly, int &size)
{
    int *coeff_ptr = poly->coeff_array;
    for (int i = 0; i < size + 1; i++) // i là cột, thì 0-n là n+1 cột rồi nè
    {
        coeff_ptr[i] = 0;
        for (int j = 0; j < size; j++)
        {
            coeff_ptr[i] += matrix[j][i];
        }
    }
}

void zero_polynomial(POLYNOMIAL poly) // cho tất cả các hệ số và bậc cao nhất =0
{
    for (int i = 0; i <= MAX_SIZE; i++)
        poly->coeff_array[i] = 0;
    poly->high_power = 0;
}

void display_polynomial(POLYNOMIAL poly, int &size) // s
{
    poly->high_power = size; // poly->high_power = rows
    for (int i = 0; i <= size; i++)
    {
        if (poly->coeff_array[i] != 0)
        {
            if (poly->coeff_array[i] > 0 && i != 0)
                cout << " + ";
            else if (poly->coeff_array[i] < 0)
                cout << " - ";
            if (abs(poly->coeff_array[i]) != 1)
                cout << abs(poly->coeff_array[i]);
            if (abs(poly->coeff_array[i]) == 1 && i == size)
                cout << 1;
            if (abs(poly->coeff_array[i]) > 0 && i < size)
            {
                cout << "x";
                if (i < size - 1)
                    cout << "^" << size - i;
            }
        }
    }
}

int TurnIntoTriangleMatrix(float matrix[][MAX_SIZE], int size1, float triangle_matrix[][MAX_SIZE], int size2);
void PermuteRow(float matrix[][MAX_SIZE], int size, int row1, int row2);
float CalculatePx(POLYNOMIAL poly, float x);

float CalculatePx(POLYNOMIAL poly, float x)
{
    float Px = 0;
    for (int i = 0; i <= poly->high_power; i++)                    // i<=4
        Px += pow(x, i) * poly->coeff_array[poly->high_power - i]; // coeff_array[3]
    return Px;
}
/*
    i=0, x^0 * coeff_array[4]
    i=1, x^1 * coeff_array[3]
    i=2, x^2 * coeff_array[2]
    i=3, x^3 * coeff_array[1]
    i=4, x^4 * coeff_array[0]
*/

int TurnIntoTriangleMatrix(float matrix[][MAX_SIZE], int size1, float triangle_matrix[][MAX_SIZE], int size2)
{
    int i, j, k;
    float m;
    int o, p;
    size2 = size1;
    for (i = 0; i < size2; i++)
    {
        for (j = 0; j <= size2; j++)
            triangle_matrix[i][j] = matrix[i][j];
    }

    for (o = 0; o < size2; o++)
    {
        for (p = 0; p < size2 + 1; p++)
            cout << setw(8) << setprecision(3) << triangle_matrix[o][p];
        cout << endl;
    }

    for (i = 0; i < size2; i++)
    {
        if (triangle_matrix[i][i] == 0)
        {
            for (k = 1; k <= size2; k++)
            {
                if (triangle_matrix[k][i] != 0)
                    break;
                if (k == size2)
                    return 1; // Case ma trận là ma trận tam giác trên sẵn
            }
            // fix here
            cout << endl
                 << "Đổi dòng " << i + 1 << " & " << k + 1 << endl;
            PermuteRow(triangle_matrix, size2, i, k);
            if (k > size2)
                return 0; // Case ?
        }

        for (j = i + 1; j <= size2; j++)
        {
            m = -triangle_matrix[j][i] / triangle_matrix[i][i];
            if (m)
            {
                cout << endl
                     << "Dòng " << j + 1;
                if (m > 0)
                    cout << " + ";
                else
                    cout << " - ";
                if (abs(m) != 1)
                    cout << abs(m) << "*";
                cout << "Dòng " << i + 1 << " ->" << " Dòng " << j + 1 << endl;
                for (k = i; k <= size2 + 1; k++)
                    triangle_matrix[j][k] += triangle_matrix[i][k] * m;
                for (o = 0; o < size2; o++)
                {
                    for (p = 0; p < size2 + 1; p++)
                        cout << setw(8) << setprecision(3) << triangle_matrix[o][p];
                    cout << endl;
                }
            }
        }
    }
    return 0;
}

int findCases(float triangle_matrix[][MAX_SIZE], int size)
{
    int countA = 0, countAx = 0;
    // Check A
    for (int i = 0; i < size; i++)
    {
        bool allZero = true;
        for (int j = i; j < size; j++)
        { // Check elements after diagonal
            if (triangle_matrix[i][j] != 0.0f)
            {
                allZero = false;
                break;
            }
        }
        if (allZero)
            countA++;
    }
    // Check Ax
    for (int i = 0; i < size; i++)
    {
        bool allZero = true;
        for (int j = i; j <= size; j++)
        { // Check elements after diagonal
            if (triangle_matrix[i][j] != 0.0f)
            {
                allZero = false;
                break;
            }
        }
        if (allZero)
            countAx++;
    }
    if (countA == countAx && countA > 0)
        return 0;
    if (countA == countAx && countA == 0)
        return 1;
    return 2;
}

int SolveTriangleMatrix(float triangle_matrix[][MAX_SIZE], int size, float resVector[MAX_SIZE])
{
    if (findCases(triangle_matrix, size) == 0)
        return 0; // Có vô số nghiệm
    if (findCases(triangle_matrix, size) == 2)
        return 2; // Vô nghiệm
    int i, k;
    float sub;
    for (i = size - 1; i >= 0; i--) // i=3,
    {
        sub = triangle_matrix[i][size];
        for (k = i + 1; k < size; k++)
            sub -= triangle_matrix[i][k] * resVector[k];
        if (triangle_matrix[i][i] != 0)
            resVector[i] = sub / triangle_matrix[i][i];
    }
    return 1;
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
    for (iACol = 0; iACol < size + 1; iACol++)
    {
        tmp = matrix[row1][iACol];
        matrix[row1][iACol] = matrix[row2][iACol];
        matrix[row2][iACol] = tmp;
    }
}

void savepoly_resToFile(POLYNOMIAL poly, float resVector[MAX_SIZE], int size, string filename, int preChoice)
{
    ofstream file;
    file.open(filename, ios ::out | ios ::app);
    ;
    if (!file.is_open())
    {
        cout << endl
             << "Không thể mở file để nhập kết quả" << endl;
        return;
    }
    else
    {
        switch (preChoice)
        {
        case 2:
        {
            file << endl
                 << "Đa thức P(x):" << endl;
            poly->high_power = size;
            for (int i = 0; i <= size; i++)
            {
                if (poly->coeff_array[i] != 0)
                {
                    if (poly->coeff_array[i] > 0 && i != 0)
                        file << " + ";
                    else if (poly->coeff_array[i] < 0)
                        file << " - ";
                    if (abs(poly->coeff_array[i]) != 1)
                        file << abs(poly->coeff_array[i]);
                    if (abs(poly->coeff_array[i]) == 1 && i == size)
                        file << 1;
                    if (abs(poly->coeff_array[i]) > 0 && i < size)
                    {
                        file << "x";
                        if (i < size - 1)
                            file << "^" << size - i;
                    }
                }
            }
            file << endl;
            break;
        }
        case 3:
        {
            file << endl
                 << "Vector nghiệm :" << endl;
            for (int i = 0; i < size; i++)
                file << setw(8) << setprecision(3) << resVector[i] << " ";
            file << endl;
            break;
        }
        }
        file << endl;
    }
    file.close();
}