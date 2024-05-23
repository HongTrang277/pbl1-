#include <bits/stdc++.h>
#include <fstream>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"

using namespace std;

bool is_Vietnamese = true;

int Continue();
int savePermit();
void Menu();

void Intro()
{
    system("cls");  
    cout << endl;
        cout << "==============================================================================================" << endl;
        cout << "|                                         | Group 8 |                                         |" << endl;
        cout << "|                                          TOPIC 901                                          |" << endl;
        cout << "|                    Solve linear matrix of coefficients by selectable method                 |" << endl;
        cout << "|                            ( Gauss Elimination Implementation )                             |" << endl;
        cout << "|---------------------------------------------------------------------------------------------|" << endl;
        cout << "|                Description                  |                    Author                     |" << endl;
        cout << "|---------------------------------------------------------------------------------------------|" << endl;
        cout << "|                                             |                                               |" << endl;
        cout << "| - Read matrix with input from file or input |           -------------------------           |" << endl;
        cout << "|   manually, turn it to triangle matrix and  |           |   Phan Thanh Truong   |           |" << endl;
        cout << "|   show transformation steps                 |           -------------------------           |" << endl;
        cout << "| - Solve upper triangle matrix, print result |                                               |" << endl;
        cout << "|   and polinomial P(x) that has coefficients |                                               |" << endl;
        cout << "|   calculated by sum of corresponding cols   |           -------------------------           |" << endl;
        cout << "| - Calculate Q(x) = Sum (p(xi))              |           | Nguyen Thi Hong Trang |           |" << endl;
        cout << "| - Save data to file                         |           -------------------------           |" << endl;
        cout << "|                                             |                                               |" << endl;
        cout << "==============================================================================================" << endl;
        cin.get();
}
float console() {
    float choose;
    do 
    {
        cout << endl;
        cout << "=========== Simple matrix calculator ===========" << endl;
        cout << "|                                              |" << endl;
        cout << "|   1. Input matrix manually                   |" << endl;
        cout << "|   2. Read matrix from file                   |" << endl;
        cout << "|   3. Turn into upper triangle matrix         |" << endl;
        cout << "|   4. Solve upper triangle matrix             |" << endl;
        cout << "|   5. Print polynomial p(x) to terminal       |" << endl;
        cout << "|   6. Calculate q(x)= SUM(p(xi))              |" << endl;
        cout << "|   7. Close program                           |" << endl;
        cout << "|                                              |" << endl;
        cout << "================================================" << endl;
        cout << "Choose your option: ";
        cin >> choose;
        cin.ignore(1000 , '\n');

        if (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1))) 
        {
            system("cls");
            cout << endl << "Invalid input!" << endl;
        } 
        else {
            break;
        }
    } while (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1)));
    return choose;
}


void Menu()
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
            SavedValidMatrices(matrix,size,valid_matrix,size1);
            if (valid_matrix[0][0] == (float)TRASHVALUE)
                cout << "You haven't input any" << endl;
            else 
            {
                cout << endl << "Linear Matrix :" << endl;
                printMatrix(valid_matrix,size1);
            }
            nextstep = savePermit();
            if (nextstep == 1)
            {
                if (valid_matrix[0][0] == (float)TRASHVALUE)
                cout << "You haven't input a valid matrix" << endl;
                else
                {
                    preChoice = 0;
                    saveMatrixToFile(valid_matrix,size1,"result.txt", preChoice);
                    cout << "Saved to file: result.txt" << endl;
                }
            }
            nextstep = Continue();
            if (nextstep == 1) goto INPUTMANUALLY;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 2:
        {
            READFILE:
            system("cls");
            cout << "======= Choose input method =======" << endl;
            cout << "|                                  |" << endl;
            cout << "|   1. Input file name             |" << endl;
            cout << "|   2. Input direct path           |" << endl;
            cout << "|                                  |" << endl;
            cout << "===================================" << endl;
            cout << "Choose your option: ";
            cin >> userChoice;
            cin.ignore(1000 , '\n');
            cin.get();
            switch (userChoice)
            {
                case 1:
                {
                    cout << "Name the file that contains input matrix: ";
                    preChoice = 9;
                    break;
                }
                case 2:
                {
                    cout << "Input direct path leads to the file : ";
                    preChoice = 10;
                    break;
                }
                default:
                {    
                    cout << " Not a choice?";
                }
            }
	        getline(cin, fileName);
            switch (matrix_reader(fileName, matrix, size))
            {
                case 0:
                {
                    if (preChoice == 9)
                        cout << endl << "File doesn't exist in the same folder" << endl;
                    if (preChoice == 10)
                        cout << endl << "Unable to open file" << endl;
                    break;
                }
                case 1:
                {
                    cout << endl << "Number of rows and columns that do not fit the matrix [n,n+1]" << endl;
                    break;
                }
                case 2:
                {
                    cout << endl << "Read matrix from file \"" << fileName << "\" succeed" << endl;
                    SavedValidMatrices(matrix,size,valid_matrix,size1);
                    if (valid_matrix[0][0] == (float)TRASHVALUE)
                        cout << "You haven't input any" << endl;
                    else 
                    {
                        cout << endl << "Linear Matrix :" << endl;
                        printMatrix(valid_matrix,size1);
                        nextstep = savePermit();
                        if (nextstep == 1)
                        {
                            if (valid_matrix[0][0] == (float)TRASHVALUE)
                            cout << "You haven't input a valid matrix" << endl;
                            else
                            {
                                preChoice = 0;
                                saveMatrixToFile(valid_matrix,size1,"result.txt", preChoice);
                                cout << "Saved to file: result.txt" << endl;
                            }
                        }
                    }
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
            GEI:
            system("cls");
            if (valid_matrix[0][0] == (float)TRASHVALUE)
                cout << endl << "Lack of input matrix, requires input!" << endl;
            else
            {
                size2 = size1;
                TurnIntoTriangleMatrix(valid_matrix,size1, triangle_matrix, size2);
                cout << "Finish Gaussion elimination implementation" << endl;
                if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                    cout << "You haven't calculate triangle matrix" << endl;
                else 
                {
                    cout << "Triangle Matrix : " << endl;
                    printMatrix(triangle_matrix,size2);
                    nextstep = savePermit();
                    if (nextstep == 1)
                    {
                        if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                            cout << "You haven't calculate any triangle matrix" << endl;
                        else 
                        {
                            preChoice = 1;
                            saveMatrixToFile(triangle_matrix,size2,"result.txt", preChoice);
                            cout << "Saved to file: result.txt" << endl;
                        }
                    }
                }
            }
            nextstep = Continue();
            if (nextstep == 1) goto GEI;
            if (nextstep == 2) goto MENU;
            break;
        }
        // Add code to make it shows the details transformations and shows result
        case 4:
        {
            SolveTriangleMatrix:
            system("cls");
            if (triangle_matrix[0][0] == (float)TRASHVALUE)
                cout << "You haven't calculate any triangle matrix" << endl;
            else 
            {
                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                {
                    cout << "Impossible equation!" << endl;
                }
                else
                {
                    cout << "Triangle matrix solved !" << endl;
                    cout << endl << "Result vector :" << endl;
                    for (int i =0 ; i <size; i++ )
                        cout << setw(8) << setprecision(3) << resVector[i] << " ";
                    cout << endl;
                    nextstep = savePermit();
                    if (nextstep == 1)
                    {
                        if (resVector[0] == (float)TRASHVALUE)
                            cout << "You haven't solve linear Matrix" << endl;
                        else
                        {
                            preChoice = 3;
                            savepoly_resToFile(poly , resVector, size, "result.txt", preChoice);
                            cout << "Saved to file: result.txt" << endl;
                        }
                    }
                }
            }
            cout << "Press Enter to back to MENU" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        case 5:
        {
            PRINTPOLYNOMIAL:
            system("cls");
            zero_polynomial(poly);
            for (i =0; i<size1; i++)
                for (int j=0; j<=size1; j++)
                    poly->coeff_array[j]+=valid_matrix[i][j];
            cout <<"Polynomial:"<<endl;
            display_polynomial(poly,size1); 
            cout << endl;
            nextstep = savePermit();
            if (nextstep == 1)
            {
                if (poly->high_power == 0)
                    cout << "You haven't input matrix" << endl;
                else
                {   preChoice = 2;
                    savepoly_resToFile(poly , resVector, size, "result.txt", preChoice);
                    cout << "Saved to file: result.txt" << endl;
                }
            }
            nextstep = Continue();
            if (nextstep == 1) goto PRINTPOLYNOMIAL;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 6:
        {
            CalculateQx:
            system("cls");
            if (resVector[0] == (float)TRASHVALUE)
            {
                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                    cout << " Impossible matrix , can not calculate without result vector!" << endl;
                else
                    cout << "You haven't calculate anything" << endl;
            }
            else
            {
                Qx = 0;
                for (i = size1-1; i>=0; i--)
                {
                    Qx += CalculatePx(poly,resVector[i]);
                }
                cout << " Result of Q(x) = SUM(P(xi)) with i=(1,n) :" << endl;
                cout << setw(15) << setprecision(3) << Qx << endl;
            }
            cout << "Press Enter to back to MENU" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        default:
            break;
    }
    cout << "PROGRAM CLOSED";

}

int Continue() 
{
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

int savePermit()
{
    cout << " Do you want to save to file ? ";
    cout << endl << "Press y for \"Yes\"" << endl << "Press n or any key for \"No\" " ;
	char input;
    input = getchar();
    cin.ignore(1000 , '\n');
	if (input == 'y')
		return 1;
    return 0;
}