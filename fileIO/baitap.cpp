/******************************
Yêu cầu:  

	Cho phép nhập vào tên file chứa dữ liệu đầu vào 
	Hiển thị thông báo trong trường hợp file không tồn tại hoặc dữ liệu không phù hợp 

Gợi ý: 
Chương trình cần có các hàm sau: 

	Hàm đọc file & lưu vào cho biến 
	Hàm ghi dữ liệu từ biến vào file 
	Hàm tính đồng thời ma trận tổng, ma trận tích 
	Hàm xuất mảng 2 chiều (ma trận vuông)

******************************/

#include <bits/stdc++.h> 
#include <fstream>
using namespace std;

#define MAX_SIZE 100

int matrix_reader(string file, float matrix[][MAX_SIZE], int &size);
void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
void saveMatrixToFile(float result1[][MAX_SIZE], float result2[][MAX_SIZE], int size, int col1, int col2, string filename);
void multiplyMatrix(float matrix[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE]);
void sumMatrix ( float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size , float result[][MAX_SIZE]);
void PermuteCol(float matrix[][MAX_SIZE], int size, int col1, int col2);

int main()
{
	int size1,size2;
	string fileName1,fileName2;

	float matrix1[MAX_SIZE][MAX_SIZE];
	float matrix2[MAX_SIZE][MAX_SIZE];
	float result1[MAX_SIZE][MAX_SIZE]; // ma trận tổng
	float result2[MAX_SIZE][MAX_SIZE]; // ma trận tích
	
	cout << "Nhập tên file chứa ma trận 1: ";
	getline(cin, fileName1);

    if (matrix_reader(fileName1, matrix1, size1) == 0 )
    {
        cout << "Không mở được file/file không tồn tại trong cùng folder" << endl;
    }
    if (matrix_reader(fileName1, matrix1, size1) == 1 )
    {
        cout << "Không phải ma trận vuông" << endl;
    }

	cout << "Nhập tên file chứa ma trận 2: ";
	getline(cin, fileName2);

    if (matrix_reader(fileName2, matrix2, size2) == 0)
    {
        cout << "Không mở được file/file không tồn tại trong cùng folder" << endl;
    }
    if (matrix_reader(fileName2, matrix2, size2) == 1)
    {
        cout << "Không phải ma trận vuông" << endl;
    }

    if(matrix_reader(fileName1, matrix1, size1) != 2 || matrix_reader(fileName2, matrix2, size2) != 2)
    {
        cout << "Thiếu ma trận đầu vào, chương trình kết thúc" << endl;
    }
    
	if(matrix_reader(fileName1, matrix1, size1) == 2 && matrix_reader(fileName2, matrix2, size2) == 2)
    {
        if (size1!=size2)
		{
			cout << "Hai ma trận khác kích thước!";
			return 0; 
		}
		int size=size1;
        int p, q;
        cout << "Nhập cột p và q của ma trận tích mà bạn muốn đổi chỗ (p,q có giá trị từ 0 - " << size-1  << "): " ;
        cin >> p; cin >> q;
		sumMatrix(matrix1, matrix2, size, result1);
        cout << "Ma trận tổng" << endl;
        printMatrix(result1, size);
        multiplyMatrix(matrix1, matrix2, size, result2);
        cout << "Ma trận tích" << endl;
        printMatrix(result2, size);
        saveMatrixToFile(result1, result2, size, p, q, "file_3.txt");
        cout << "Ma trận tích đã đổi cột" << endl;
        printMatrix(result2, size);
    }

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

void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size) 
{
	for (int i=0; i<size; i++) 
	{
		for(int j=0; j<size; j++) 
			cout<< matrix[i][j] << " ";
		cout<<endl;
	}
}

void saveMatrixToFile(float result1[][MAX_SIZE],float result2[][MAX_SIZE], int size, int col1, int col2, string filename) 
{
    ofstream file(filename);
    if (!file.is_open()) 
	{
        cout<< "Không thể mở file" <<endl;
        return;
    } 
	else 
	{
		file << "Ma trận tổng:" << endl;
		for (int i = 0; i < size; ++i) 
		{
        	for (int j = 0; j < size; ++j) 
            file << result1[i][j] << " ";
        file << endl;
    	}
        file << "Ma trận tích:" << endl;
		for (int i = 0; i < size; ++i) 
		{
        	for (int j = 0; j < size; ++j) 
            file << result2[i][j] << " ";
        file << endl;
    	}
        PermuteCol(result2, size, col1, col2);
        file << "Ma trận tích đã đổi chỗ cột p và q:" << endl;
		for (int i = 0; i < size; ++i) 
		{
        	for (int j = 0; j < size; ++j) 
            file << result2[i][j] << " ";
        file << endl;
    	}
    file.close();
	}
}

void multiplyMatrix(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE]) 
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
}

void sumMatrix( float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size, float result[][MAX_SIZE]) 
{
	int i, j, k;
	for(int i=0; i<size; i++) 
	{
		for(int j=0; j<size; j++) 
			result[i][j]=matrix1[i][j]+matrix2[i][j];
	}
}

void PermuteCol(float matrix[][MAX_SIZE], int size, int col1, int col2)
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
}

