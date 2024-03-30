#include <bits/stdc++.h>
#include <fstream>

#define MAX_SIZE 100
#define TRASHVALUE 12345.6789

using namespace std;

int matrix_reader(string file, float matrix[][MAX_SIZE], int &size);
void multiplyMatrix(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE], int &preChoice);
void sumMatrix ( float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size , float result[][MAX_SIZE], int &preChoice);
void inputMatrixManually(float matrix[][MAX_SIZE], int &size);
void PermuteCol(float matrix[][MAX_SIZE], int size, int col1, int col2, int &preChoice);
void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
void saveMatrixToFile(float result[][MAX_SIZE], int size, string filename, int preChoice, int col1, int col2);
void dynamicallySavedMatrices(float matrix1[][MAX_SIZE],int &size1,float matrix2[][MAX_SIZE],int &size2,float matrix[][MAX_SIZE],int size);
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
        cout << "|   3. Matrices addition                       |" << endl;
        cout << "|   4. Matrices multiplication                 |" << endl;
        cout << "|   5. Permute 2 collumns of result matrix     |" << endl;
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
                    cout << endl << "Read matrix from file \"" << fileName << "\" succeed" << endl;
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
                    cout << "Matrices sizes are not the same" << endl;
                }
                else
                {
                    sumMatrix(matrix1, matrix2, size1, result, preChoice);
                    cout << "Finish calculation" << endl;
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
                    cout << "Matrices sizes are not the same" << endl;
                }
                else
                {
                    multiplyMatrix(matrix1, matrix2, size1, result, preChoice);
                    cout << "Finish calculation!" << endl;
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
                if (col1 < 0 || col1 > size-1)
                    cout << "Invaliid collumn"; goto INVALID;
                cout << "Col 2: "; cin >> col2;
                if (col2 < 0 || col2 > size-1)
                    cout << "Invaliid collumn"; goto INVALID;
                PermuteCol(result, size1, col1, col2, preChoice);
                cout << " Collumns permuted" << endl;
                cin.ignore(1000 , '\n');
            }
            else
                cout << "No calculation was made!" << endl;
            INVALID:
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

/*
    hàm này đọc ma trận từ file text
    string file: tên file text tồn tại trong cùng folder
    int matrix[][]: Ma trận 2 chiều sẽ lưu ma trận đọc được, ma trận mặc định truyền theo tham chiếu
    int &size: Kích thước của ma trận, vì là ma trận vuông nên số hàng = số cột. 
    Dùng tham chiếu để biến trong hàm main cũng bị thay đổi
*/
int matrix_reader(string file, float matrix[][MAX_SIZE], int &size)
{
    size = -1; // Khởi tạo kích thước ma trận là -1. Tức là chưa biết kích thước
    ifstream whatToRead;
    whatToRead.open(file);
    if (whatToRead.fail())
        return 0;
    string line;
    int rows, cols;
    for(rows = 0; getline( whatToRead, line ); ++rows)
    {
        string element = "";
        cols = 0;
        for(int t = 0; t < line.length(); ++t)
        {
            if(line[t] != ' ')
            {
                element += line[t];
            }
            if(line[t] == ' ' || t == line.length() - 1)
            {
                // Hàm atoi nhận vào biến kiểu char*, nên cần dùng .c_str() để chuyển từ string về char*
                matrix[rows][cols] = atoi(element.c_str());
                cols++;
                // Đặt lại giá trị element
                element = ""; 
            }
        }
        // Nếu chưa gán giá trị kích thước ma trận thì gán trước.
        // lấy số phần tử của hàng đầu tiên làm giá trị khởi tạo cho kích thước ma trận
        if(size == -1) size = cols;
        // Nếu số cột của một hàng bất kỳ khác kích thước => ko phải ma trận vuông
        if(size != cols) return 1;
    }
    // Nếu số hàng của ma trận khác kích thước => ko phải ma trận vuông
    if(size != rows) return 1;
    whatToRead.close();
    return 2;
}

void saveMatrixToFile(float result[][MAX_SIZE], int size, string filename, int preChoice, int col1, int col2) 
{
    ofstream file;
    file.open(filename, ios :: out | ios :: app);;
    if (!file.is_open()) 
	{
        cout << endl <<  "Không thể mở file để nhập kết quả" <<endl;
        return;
    } 
	else 
	{
        switch (preChoice)
        {
            case 0:
            {
                file << endl << "Multiplication matrix  :" << endl;
                break;
            }
            case 1:
            {
                file << endl << "Summation matrix:" << endl;
                break;            
            }
            case 2:
            {
                file << endl << "Previous result matrix that has permute collumn " << col1 << " and " << col2 << ":" << endl;
                break;            
            }
        }
		for (int i = 0; i < size; ++i) 
		{
        	for (int j = 0; j < size; ++j) 
            file << setw(8) << setprecision(3) << result[i][j];
        file << endl;
    	}
    file.close();
	}
}

void inputMatrixManually(float matrix[][MAX_SIZE], int &size)
{
    cout << endl << "Input matrix manually:" << endl;
    cout << "Input matrix size:";
    cin >> size;
    for (int i = 0 ; i < size; i++ )
        for (int j = 0 ; j < size; j++)
            cin >> matrix[i][j];
}

void multiplyMatrix(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE], int &preChoice) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    preChoice = 0;
}

void sumMatrix( float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE], int &preChoice) 
{
	for(int i=0; i<size; i++) 
	{
		for(int j=0; j<size; j++) 
			result[i][j]=matrix1[i][j]+matrix2[i][j];
	}
    preChoice = 1;
}

void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size) 
{
	for (int i=0; i<size; i++) 
	{
		for(int j=0; j<size; j++) 
			cout << setw(8) << setprecision(3) << matrix[i][j];
		cout<<endl;
	}
}

void PermuteCol(float matrix[][MAX_SIZE], int size, int col1, int col2, int &preChoice)
{
    int iARow, iACol;
    int tmp;
 
    if (col1 < 0 || col1 >= size ||
        col2 < 0 || col2 >= size ||
        col1 == col2)
    {
        return;
    }
 
    // Duyệt theo hàng
    for (iARow = 0; iARow < size; iARow++)
    {
        tmp = matrix[iARow][col1];
        matrix[iARow][col1] = matrix[iARow][col2];
        matrix[iARow][col2] = tmp;
    }
    preChoice=2;
}


void dynamicallySavedMatrices(float matrix1[][MAX_SIZE],int &size1,float matrix2[][MAX_SIZE],int &size2,float matrix[][MAX_SIZE],int size)
{
    int i, j;
    if (matrix1[0][0] != (float)TRASHVALUE)
	{
        size2= size1;
        for(i=0; i<size2; i++) 
        {
            for(j=0; j<size2; j++) 
                matrix2[i][j] = matrix1[i][j];
        }
    }
    size1= size;
	for(i=0; i<size1; i++) 
	{
		for(j=0; j<size1; j++) 
			matrix1[i][j] = matrix[i][j];
	}
}