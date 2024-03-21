#include <bits/stdc++.h>

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

float console() {
    float choose;
    do 
    {
        cout << endl;
        cout << "=========== Simple matrix calculator ===========" << endl;
        cout << "|   1. Input matrix manually                    |" << endl;
        cout << "|   2. Read matrix from file                    |" << endl;
        cout << "|   3. Matrices addition                        |" << endl;
        cout << "|   4. Matrices multiplication                  |" << endl;
        cout << "|   5. Permute 2 collumns of result matrix      |" << endl;
        cout << "|   6. Save result to file                      |" << endl;
        cout << "|   7. Print matrix to terminal                 |" << endl;
        cout << "|   8. Close program                            |" << endl;
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

int Continue() {
	cout << endl << "Press y to continue input!" << endl << "Press b to back to menu!" ;
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
    ofstream file(filename);
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
            }
            case 1:
            {
                file << endl << "Summation matrix:" << endl;
            }
            case 2:
            {
                file << endl << "Previous result matrix that has permute collumn " << col1 << " and " << col2 << ":" << endl;
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


/*
Hàm này mục đích là để lưu các ma trận theo tuần tự, nhập ma trận vào thì sẽ lưu tạm vào ma trận matrix
Sau đó nếu ma trận hợp lệ, chuẩn ma trận vuông thì sẽ lưu matrix->matrix2, lúc này matrix1 sẽ rỗng
Ma trận mới cũng sẽ lưu vào matrix, sau đó nếu chuẩn thì sẽ lưu 
*/
void dynamicallySavedMatrices(float matrix1[][MAX_SIZE],int &size1,float matrix2[][MAX_SIZE],int &size2,float matrix[][MAX_SIZE],int size)
{
    int i, j;
    size1= size2;
    if (matrix1[0][0] != (float)TRASHVALUE)
	{
        for(i=0; i<size1; i++) 
        {
            for(j=0; j<size1; j++) 
                matrix1[i][j] = matrix2[i][j];
        }
    }
    size2= size;
	for(i=0; i<size2; i++) 
	{
		for(j=0; j<size2; j++) 
			matrix2[i][j] = matrix[i][j];
	}
}