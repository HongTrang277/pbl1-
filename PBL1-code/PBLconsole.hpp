#include <bits/stdc++.h>
#include <fstream>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"
#include "PBLpolynomial.hpp"

using namespace std;

bool is_Vietnamese = true;

int Continue();
void Menu();

float console() {
    float choose;
    do 
    {
        cout << endl;
        cout << "=========== Simple matrix calculator ===========" << endl;
        cout << "|   1. Input matrix manually                   |" << endl;
        cout << "|   2. Read matrix from file                   |" << endl;
        cout << "|   3. Turn into upper triangle matrix         |" << endl;
        cout << "|   4. Print polynomial p(x) to terminal       |" << endl;
        cout << "|   5. Calculate q(x)= SUM(p(xi))              |" << endl;
        cout << "|   6. Save result to file                     |" << endl;
        cout << "|   7. Print matrix to terminal                |" << endl;
        cout << "|   8. Close program                           |" << endl;
        cout << "================================================" << endl;
        cout << "Choose your option: ";
        cin >> choose;
        cin.ignore(1000 , '\n');

        if (!((choose == static_cast<int>(choose)) && (choose <= 8 && choose >= 1))) 
        {
            system("cls");
            cout << endl << "Invalid input!" << endl;
        } 
        else {
            break;
        }
    } while (!((choose == static_cast<int>(choose)) && (choose <= 8 && choose >= 1)));
    return choose;
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

    /*
    cout << "=====Chọn ngôn ngữ/Choose language=====" << endl;
    cout << "|       1 . Tiếng Việt                |" << endl;
    cout << "|       2 . English                   |" << endl;
    cout << "=======================================" << endl;

    cout << "Nhập lựa chọn // Input choice :"; cin >> userChoice;
    cin.ignore(1000 , '\n');
    if (userChoice == 1) goto MENU:
    is_Vietnamese = !is_Vietnamese;
    */

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
                    cout << endl << "Not a matrix of order (n,n+1)" << endl;
                    break;
                }
                case 2:
                {
                    cout << endl << "Read matrix from file \"" << fileName << "\" succeed" << endl;
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
            Func1Name:
            system("cls");
            /*
             code 
            */
            nextstep = Continue();
            if (nextstep == 1) goto Func1Name;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 4:
        {
            PRINTPOLYNOMIAL:
            system("cls");
            cout<<"Polynomial:"<<endl;
            display_polynomial(poly,size); // vector nghiệm sẽ là cái coeff_array[MAX_SIZE] á, tạo 1 cái biến POLYNOMIAL trỏ tới coeff_array là dc
            nextstep = Continue();
            if (nextstep == 1) goto PRINTPOLYNOMIAL;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 5:
        {
            Func3Name:
            




            INVALID:
            nextstep = Continue();
            if (nextstep == 1) goto Func3Name;
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

int Continue() {
	cout << endl << "Press y to repeat step!" << endl << "Press b to back to menu!" ;
    cout << endl << "Press any key to exit program!" << endl << "Input: ";
	char input;
    input = getchar();
    cin.ignore(1000 , '\n');
	if (input == 'y')
		return 1;
	if (input == 'b')
		return 2;
    return 0;
}
