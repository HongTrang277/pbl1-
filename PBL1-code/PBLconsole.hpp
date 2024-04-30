#include <bits/stdc++.h>
#include <fstream>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"

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
        cout << "|                                              |" << endl;
        cout << "|   1. Input matrix manually                   |" << endl;
        cout << "|   2. Read matrix from file                   |" << endl;
        cout << "|   3. Turn into upper triangle matrix         |" << endl;
        cout << "|   4. Print polynomial p(x) to terminal       |" << endl;
        cout << "|   5. Calculate q(x)= SUM(p(xi))              |" << endl;
        cout << "|   6. Save to file                            |" << endl;
        cout << "|   7. Print matrix to terminal                |" << endl;
        cout << "|   8. Close program                           |" << endl;
        cout << "|                                              |" << endl;
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

	int col1, col2;
	
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
            SavedValidMatrices(matrix,size1,valid_matrix,size2);
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
                    cout << endl << "Invalid matrix" << endl;
                    break;
                }
                case 2:
                {
                    cout << endl << "Read matrix from file \"" << fileName << "\" succeed" << endl;
                    SavedValidMatrices(matrix,size1,valid_matrix,size2);
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
            if (matrix[0][0] == (float)TRASHVALUE)
                cout << endl << "Lack of input matrix, requires input!" << endl;
            else
            {
                TurnIntoTriangleMatrix(valid_matrix,size1);
                cout << "Finish Gaussion elimination implementation" << endl;
            }
            nextstep = Continue();
            if (nextstep == 1) goto GEI;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 4:
        {
            PRINTPOLYNOMIAL:
            system("cls");
            cout <<"Polynomial:"<<endl;
            display_polynomial(poly,size); 
            cout << endl;
            nextstep = Continue();
            if (nextstep == 1) goto PRINTPOLYNOMIAL;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 5:
        {
            CalculateQx:
            system("cls");
            if (resVector[0] == (float)TRASHVALUE)
                        cout << "You haven't calculate anything" << endl;
            else
            {
                Qx = 0;
                for (i = size1; i>=1; i--)
                {
                    Qx += CalculatePx(poly,resVector[i]);
                }
                cout << " Result of Q(x) = SUM(P(xi)) with i=(1,n) :" << endl;
                cout << setw(15) << setprecision(3) << Qx;
            }
            cout << "Press Enter to back to MENU" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        case 6:
        {
            system("cls");
            cout << "======What do you want to save to file?======" << endl;
            cout << "|                                            |" << endl;
            cout << "|  1. Input matrix (Your latest valid input) |" << endl;
            cout << "|  2. Triangle matrix (Latest calcutlation)  |" << endl;
            cout << "|  3. Save polynomial to file                |" << endl;
            cout << "|  4. Save result vector to file             |" << endl;
            cout << "|                                            |" << endl;
            cout << "==============================================" << endl << endl;
            cout << "Enter number of choice:" << endl;
            cin >> userChoice;
            switch (userChoice)
            {
                case 1:
                {
                    system("cls");
                    if (valid_matrix[0][0] == (float)TRASHVALUE)
                        cout << "You haven't input a valid matrix" << endl;
                    else
                    {
                        saveMatrixToFile(valid_matrix,size1,"result.txt", preChoice,col1,col2);
                        cout << "Saved to file: result.txt" << endl;
                    }
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
                    if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                        cout << "You haven't calculate any triangle matrix" << endl;
                    else 
                    {
                        saveMatrixToFile(triangle_matrix,size1,"result.txt", preChoice,col1,col2);
                        cout << "Saved to file: result.txt" << endl;
                    }
                    cout << "Press Enter to back to MENU" << endl;
                    cin.ignore(1000 , '\n');
                    cin.get();
                    goto MENU;
                    break;
                }
                case 3:
                {
                    system("cls");
                    if (poly->high_power == 0)
                        cout << "You haven't input matrix" << endl;
                    else
                    {
                        savepoly_resToFile(poly , resVector, size, "result.txt", preChoice);
                        cout << "Saved to file: result.txt" << endl;
                    }
                    cout << "Press Enter to back to MENU" << endl;
                    cin.ignore(1000 , '\n');
                    cin.get();
                    goto MENU;
                    break;
                }
                case 4:
                {
                    system("cls");
                    if (resVector[0] == (float)TRASHVALUE)
                        cout << "You haven't solve linear Matrix" << endl;
                    else
                    {
                        saveMatrixToFile(valid_matrix,size1,"result.txt", preChoice,col1,col2);
                        cout << "Saved to file: result.txt" << endl;
                    }
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
        case 7:
        {
            PRINT:
            system("cls");
            cout << "======Which matrix do you want do print?======" << endl;
            cout << "|                                             |" << endl;
            cout << "|  1. Input matrix (Your latest valid input)  |" << endl;
            cout << "|  2. Triangle matrix (Latest calcutlation)   |" << endl;
            cout << "|                                             |" << endl;
            cout << "==============================================" << endl << endl;
            cout << "Enter number of choice:" << endl;
            cin >> userChoice;
            switch(userChoice)
            {
                case 1:
                {
                    system("cls");
                    cout << "Linear Matrix :" << endl;
                    if (valid_matrix[0][0] == (float)TRASHVALUE)
                        cout << "You haven't input any" << endl;
                    else printMatrix(valid_matrix,size1);
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
                    if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                        cout << "You haven't calculate triangle matrix" << endl;
                    else printMatrix(triangle_matrix,size2);
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
