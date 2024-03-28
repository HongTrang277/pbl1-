#include <bits/stdc++.h> 
#include <fstream>
#include "consoleLib.hpp"

using namespace std;

#define MAX_SIZE 100
#define TRASHVALUE 12345.6789

void Menu();

int main()
{
	Menu();
	return 0;
}

void Menu()
{
    int size,size1,size2;

	string fileName;

    float matrix[MAX_SIZE][MAX_SIZE];
	float matrix1[MAX_SIZE][MAX_SIZE];
    matrix1[0][0]=(float)TRASHVALUE;
	float matrix2[MAX_SIZE][MAX_SIZE];
    matrix2[0][0]=(float)TRASHVALUE;
	float result[MAX_SIZE][MAX_SIZE]; // ma trận kết quả
    result[0][0]=(float)TRASHVALUE;
	int col1, col2;
	
    int userChoice;
    int nextstep, preChoice= -1;
    //preChoice =-1 là trước đó không có phép tính hay kết quả nào để lưu vào file

    MENU: 
	system("cls");             
	userChoice = console();
	system("cls");

    switch(userChoice)
    {
        case 1:
        {
            INPUTMANUALLY:
            system("cls");
            inputMatrixManually(matrix, size);
            cin.ignore(1000 , '\n');
            dynamicallySavedMatrices(matrix1, size1, matrix2, size2, matrix, size);
            nextstep = Continue();
            if (nextstep == 1) goto INPUTMANUALLY;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 2:
        {
            READFILE:
            system("cls");
            cout << "Name the file that contains input matrix: ";
	        getline(cin, fileName);
            switch (matrix_reader(fileName, matrix, size))
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
                    cout << endl << "Read matrix from file \"" << fileName << "\" succeed";
                    dynamicallySavedMatrices(matrix1, size1, matrix2, size2, matrix, size);
                    break;
                }
            }
            nextstep = Continue();
            if (nextstep == 1) goto READFILE;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 3:
        {
            ADD:
            system("cls");
            if (matrix1[0][0] == (float)TRASHVALUE)
                cout << "Lack of input matrix, requires input!" << endl;
            else
            {
                if (size1 != size2)
                {
                    cout << "Matrices sizes are not the same";
                }
                else
                {
                    sumMatrix(matrix1, matrix2, size1, result, preChoice);
                    cout << "Finish calculation";
                }
            }
            nextstep = Continue();
            if (nextstep == 1) goto ADD;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 4:
        {
            MULTIPLY:
            system("cls");
            if (matrix1[0][0] != (float)TRASHVALUE)
            {
                if (size1 != size2)
                {
                    cout << "Matrices sizes are not the same";
                }
                else
                {
                    multiplyMatrix(matrix1, matrix2, size1, result, preChoice);
                    cout << "Finish calculation!";
                }
            }
            else
                cout << "Lack of input matrix, requires input!" << endl;
            nextstep = Continue();
            if (nextstep == 1) goto MULTIPLY;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 5:
        {
            PERMUTECOLS:
            system("cls");
            if (result[0][0] != (float)TRASHVALUE)
            {
                cout << "Which collumns you want to permute:" << "(Enter number from 0 - "<< size-1 << ")" << endl;
                cout << "Col 1: "; cin >> col1;
                cout << "Col 2: "; cin >> col2;
                PermuteCol(result, size1, col1, col2, preChoice);
                cout << " Collumns permuted" << endl;
                cin.ignore(1000 , '\n');
            }
            else
                cout << "No calculation was made!" << endl;
            nextstep = Continue();
            if (nextstep == 1) goto PERMUTECOLS;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 6:
        {
            if (preChoice != -1)
            {
                saveMatrixToFile(result,size1,"result.txt", preChoice,col1,col2);
                cout << "Saved to file: result.txt" << endl;
            }
            else
                cout << "No calculation was made!" << endl;
            cout << "Press Enter to back to MENU " << endl;
            cin.get();
            goto MENU;
            break;
        }
        case 7:
        {
            PRINT:
            system("cls");
            cout << "====Which matrix do you want do print?====" << endl;
            cout << "|  1. Matrix 1 (Your latest valid input) |" << endl;
            cout << "|  2. Matrix 2 (Previous valid input)    |" << endl;
            cout << "|  3. Last result                        |" << endl;
            cout << "==========================================" << endl << endl;
            cout << "Enter number of choice:" << endl;
            cin >> userChoice;
            switch(userChoice)
            {
                case 1:
                {
                    system("cls");
                    cout << "Matrix 1:" << endl;
                    if (matrix1[0][0] == (float)TRASHVALUE)
                        cout << "You haven't input matrix 1" << endl;
                    else printMatrix(matrix1,size1);
                    cout << "Press Enter to back to MENU" << endl;
                    cin.ignore(1000 , '\n');
                    cin.get();
                    goto MENU;
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout << "Matrix 2: " << endl;
                    if (matrix2[0][0] == (float)(float)TRASHVALUE)
                        cout << "You haven't input matrix 2" << endl;
                    else printMatrix(matrix2,size2);
                    cout << "Press Enter to back to MENU" << endl;
                    cin.ignore(1000 , '\n');
                    cin.get();
                    goto MENU;
                    break;
                }
                case 3: 
                {
                    system("cls");
                    cout << "Your last result: " << endl;
                    if (preChoice == -1)
                        cout << "No calculation was made" << endl;
                    //chỗ này phải tạo thêm 1 biến resultSize, nếu không thì khi input thêm >=2 ma trận khác kích thước sẽ có lỗi 
                    else printMatrix(result,size1);
                    cout << "Press Enter to back to MENU" << endl;
                    cin.ignore(1000 , '\n');
                    cin.get();
                    goto MENU;
                    break;
                }
                default:
                {
                    cout << "Not a choice!?" << endl;
                    cout << "Press Enter to back to MENU" << endl;
                    cin.get();
                    goto MENU;
                }
            }

        }
        default:
            break;
    }
    cout << "PROGRAM CLOSED";

}

   