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

#define MAX 100

void readMatrixFromFile(string filename, float matrix[MAX][MAX], int rows, int cols);
void printMatrix(float matrix[MAX][MAX], int rows, int cols);
void saveMatrixToFile(int matrix[][MAX], int rows, int cols, string filename);
void multiplyMatrix(float matrix[][MAX], float matrix2[][MAX], int n,int m, int m1);
void sumMatrix ( float matrix[][MAX], float matrix2[][MAX], int m, int m1);
void swapCols(float matrix[][MAX], int aRow, int aCol, int row1, int row2);

int main()
{
	int rows1, cols1;
	int rows2, cols2;

	string fileName1,fileName2;

	float matrix1[MAX][MAX];
	float matrix2[MAX][MAX];
	
	cout << "Nhập tên file chứa ma trận 1: ";
	getline(cin, fileName1);
	cout << "Nhập tên file chứa ma trận 2: ";
	getline(cin, fileName2);	

	readMatrixFromFile(fileName1, matrix1, rows1, cols1);
	readMatrixFromFile(fileName2, matrix2, rows2, cols2);


}

void readMatrixFromFile(string filename, float matrix[MAX][MAX], int rows, int cols) 
{
	ifstream file(filename);
	if(file.is_open()) 
	{
		file >> rows >>cols;
		for(int i=0; i<rows; i++) 
		{
			for(int j=0; j<cols; j++) 
				file >> matrix[i][j];
		}
	}
	else cout<< "Không thể mở file" <<endl;
}


void printMatrix(float matrix[MAX][MAX], int rows, int cols) 
{
	for (int i=0; i<rows; i++) 
	{
		for(int j=0; j<cols; j++) 
			cout<< matrix[i][j] << " ";
		cout<<endl;
	}
}

void saveMatrixToFile(int matrix[][MAX], int rows, int cols, string filename) 
{
    ofstream file(filename);
    if (!file.is_open()) 
	{
        cout<< "Không thể mở file" <<endl;
        return;
    } 
	else 
	{
		file << rows << " " << cols << endl;
		for (int i = 0; i < rows; ++i) 
		{
        	for (int j = 0; j < cols; ++j) 
            file << matrix[i][j] << " ";
        file << endl;
    	}
    file.close();
	}
}

void multiplyMatrix(float matrix[][MAX], float matrix2[][MAX], int n,int m, int m1)
{
	float tempmatrix[MAX][MAX];
	int i, j, k;
	for(int i=0; i<n; i++) 
	{
		for(int j=0; j<m; j++) 
		{
			int tt=0;
			for(int k=0; k<m1; k++) 
				tt=matrix[i][k]*matrix2[k][i]; 
			tempmatrix[i][j]= tt;
		}
	}
}

void sumMatrix( float matrix[][MAX], float matrix2[][MAX], int m, int m1) 
{
    float tempmatrix[MAX][MAX];
	int i, j, k;
	for(int i=0; i<m; i++) 
	{
		for(int j=0; j<m; j++) 
			tempmatrix[i][j]=matrix[i][j]+matrix2[i][j];
	}
}

void swapCols(float matrix[][MAX], int aRow, int aCol, int col1, int col2)
{
    int iaRow, iaCol;
    int tmp;
	
    if (col1 < 0 || col1 >= aCol ||
        col2 < 0 || col2 >= aCol ||
        col1 == col2)
    {
        return;
    }
 
    for (iaRow = 0; iaRow < aRow; iaRow++)
    {
		//đổi chỗ 2 phần tử cùng cột khác dòng
        tmp = matrix[iaRow][col1];
        matrix[iaRow][col1] = matrix[iaRow][col2];
        matrix[iaRow][col2] = tmp;
    }
}
