#include <bits/stdc++.h>
#include <fstream>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"

using namespace std;

int Continue();
int savePermit();
void Menu();

void Intro()
{
    system("cls");  
    cout << endl;
        cout << "╔═══════════════╦═══════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║    Group 7    ║                      Đề tài 901                                   ║" << endl;
        cout << "╠═══════════════╝   Tìm nghiệm của hệ phương trình đại số tuyến tính                ║" << endl;
        cout << "║                      bằng phương pháp tự chọn ( Phép khử Gauss )                  ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "╠══════════════════════════════╦════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ║                  Phan Thanh Trường                 ║" << endl;
        cout << "║     Sinh viên thực hiện      ╠════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ║                Nguyễn Thị Hồng Trang               ║" << endl;
        cout << "╠══════════════════════════════╩════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ╔════════════════════╗                               ║" << endl;
        cout << "║                              ║ Mô tả chương trình ║                               ║" << endl;
        cout << "║                              ╚════════════════════╝                               ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "║     - Đọc dữ liệu ma trận từ bàn phím hoặc file                                   ║" << endl;
        cout << "║     - Biến đổi thành ma trận tam giác trên và thể hiện các bước biến đổi          ║" << endl;
        cout << "║     - Giải ma trận tam giác trên bằng quá trình ngược, in ra vecto nghiệm, in ra  ║" << endl;
        cout << "║       đa thức p(x) có các hệ số bằng tổng các cột                                 ║" << endl;
        cout << "║     - Tính Q(x) = Sum (p(xi)) với xi là nghiệm                                    ║" << endl;
        cout << "║     - Lưu các dữ liệu vào file                                                    ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════════════════════════════════╝" << endl;
        cin.get();
}

float console() {
    float choose;
    do 
    {
        cout << endl;
        cout << "╔═══════════ Máy tính ma trận đơn giản ══════════╗" << endl;
        cout << "║                                                ║ " << endl;
        cout << "║    1. Input matrix manually                    ║ " << endl;
        cout << "║    2. Read matrix from file                    ║ " << endl;
        cout << "║    3. Turn into upper triangle matrix          ║ " << endl;
        cout << "║    4. Solve upper triangle matrix              ║ " << endl;
        cout << "║    5. Print polynomial p(x) to terminal        ║ " << endl;
        cout << "║    6. Calculate q(x)= SUM(p(xi))               ║ " << endl;
        cout << "║    7. Save to file                             ║ " << endl;
        cout << "║    8. Close program                            ║ " << endl;
        cout << "║                                                ║ " << endl;
        cout << "╚════════════════════════════════════════════════╝" << endl;
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
	
    POLYNOMIAL poly = new polynomial;
    zero_polynomial(poly);

    int userChoice;
    int nextstep, preChoice= -1;
    int notStart = 0;

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
            else if (valid_matrix[0][0] != (float)TRASHVALUE)
            {
                cout << "Reset relevant values of previous matrix when input new matrix" << endl;
                valid_matrix[0][0]=(float)TRASHVALUE;
                triangle_matrix[0][0]=(float)TRASHVALUE;
                zero_polynomial(poly);
                resVector[0]=(float)TRASHVALUE;
            }
            else 
            {
                cout << endl << "Linear Matrix :" << endl;
                printMatrix(valid_matrix,size1);
            }
            nextstep = savePermit();
            if (nextstep == 1)
            {

                preChoice = 0;
                saveMatrixToFile(valid_matrix,size1,"result.txt", preChoice);
                cout << "Saved to file: result.txt" << endl;
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
            if (valid_matrix[0][0] != (float)TRASHVALUE)
            {
                cout << "Reset relevant values of previous matrix when input new matrix" << endl;
                valid_matrix[0][0]=(float)TRASHVALUE;
                triangle_matrix[0][0]=(float)TRASHVALUE;
                zero_polynomial(poly);
                resVector[0]=(float)TRASHVALUE;
            }
            cout << "Input file name / direct path leads to the file : ";
            getline(cin, fileName);
            switch (matrix_reader(fileName, matrix, size))
            {
                case 0:
                {
                    cout << endl << "Unable to open file" << endl;
                    break;
                }
                case 1:
                {
                    cout << endl << "Number of rows and columns that do not fit the matrix [n,n+1]" << endl;
                    break;
                }
                case 3:
                {
                    cout << endl << "Please check if the input file contains only valid numbers" << endl;
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
            notStart = 0;
            GEI:
            system("cls");
            if (valid_matrix[0][0] == (float)TRASHVALUE)
            {    
                cout << "Lack of input matrix, using default matrix!" << endl;
                matrix_reader("defaultMat.txt", valid_matrix, size1);
                Sleep(3000);
            }
            size2 = size1;
            TurnIntoTriangleMatrix(valid_matrix,size1, triangle_matrix, size2);
            cout << "Finish Gaussion elimination implementation" << endl;
            if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                cout << "You haven't calculate triangle matrix" << endl;
            else 
            {
                cout << "Triangle Matrix : " << endl;
                printMatrix(triangle_matrix,size2);
            }
            Sleep(3000);
            if (notStart)
            {
                cout << "Press Enter to continue";
                cin.get();
                goto SolveTriangleMatrix;
            }
            nextstep = Continue();
            if (nextstep == 1) goto GEI;
            if (nextstep == 2) goto MENU;
            break;
        }
        // Add code to make it shows the details transformations and shows result
        case 4:
        {
            notStart = 0;
            SolveTriangleMatrix:
            system("cls");
            if (triangle_matrix[0][0] == (float)TRASHVALUE)
            {
                cout << "You haven't calculate any triangle matrix" << endl;
                notStart++;
                Sleep(3000);
                goto GEI;
            }
            else 
            {
                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                {
                    cout << "Infinite solution!" << endl;
                }
                else if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                    cout << "Impossible equation" << endl;
                else
                {
                    cout << "Triangle matrix solved !" << endl;
                    cout << endl << "Result vector :" << endl;
                    for (int i =0 ; i <size1; i++ )
                        cout << setw(8) << setprecision(3) << resVector[i] << " ";
                    cout << endl;
                }
            }
            Sleep(3000);
            if (notStart)
            {   
                cout << "Press Enter to continue";
                cin.get();
                goto PRINTPOLYNOMIAL;
            }
            cout << "Press Enter to back to MENU" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        case 5:
        {
            notStart = 0;
            PRINTPOLYNOMIAL:
            system("cls");
            if (triangle_matrix[0][0] == (float)TRASHVALUE)
            {    
                cout << "You haven't input a valid matrix" << endl;
                notStart++;
                Sleep(3000);
                goto SolveTriangleMatrix;
            }
            else
            {    
                zero_polynomial(poly);
                for (i =0; i<size1; i++)
                    for (int j=0; j<=size1; j++)
                        poly->coeff_array[j]+=valid_matrix[i][j];
                cout <<"Polynomial:"<<endl;
                display_polynomial(poly,size1); 
                cout << endl;
            }
            Sleep(3000);
            if (notStart)
            {   
                cout << "Press Enter to continue";
                cin.get();
                goto CalculateQx;
            }
            nextstep = Continue();
            if (nextstep == 1) goto PRINTPOLYNOMIAL;
            if (nextstep == 2) goto MENU;
            break;
        }
        case 6:
        {
            notStart = 0;
            CalculateQx:
            system("cls");
            if (resVector[0] == (float)TRASHVALUE)
            {
                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                    cout << "Impossible matrix , can not calculate without result vector!" << endl;
                else if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                    cout << "Infinite solution , can not calculate!" << endl;
                else
                {    
                    cout << "You haven't calculate anything" << endl;
                    notStart++;
                    Sleep(3000);
                    goto PRINTPOLYNOMIAL;
                }
            }
            else
            {
                Qx = 0;
                for (i = size1-1; i>=0; i--)
                {
                    Qx += CalculatePx(poly,resVector[i]);
                }
                cout << "Result of Q(x) = SUM(P(xi)) with i=(1,n) :" << endl;
                cout << fixed << setw(15) << setprecision(3) << Qx << endl;
            }
            cout << "Press Enter to back to MENU" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        case 7:
        {
            
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