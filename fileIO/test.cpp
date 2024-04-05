#include <bits/stdc++.h>
#include <fstream>
#include "consoleLib.hpp"
using namespace std;
#define MAX_SIZE 100

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

void inputMatrixManually(float matrix[][MAX_SIZE], int &size)
{
    fstream file;
    string fileName="check.txt";
    cout << endl << "Input matrix manually:" << endl;
    cout << "Input matrix size:";
    cin >> size;
    cin.ignore(1000,'\n');
    string line ="";
    for (int i = 0 ; i < size; i++ )
    { 
        file.open(fileName,ios :: out|ios :: app); 
        cin >> line;
        file << line;
        file << endl;
        cin.ignore(1000,'\n');
        line = "";
        file.close();
    }
    if (matrix_reader(fileName, matrix, size)==2)
        cout << "Valid input";
    else cout << "Invalid matrix";
    file.open(fileName);
    file.close();
}

int main() 
{
    float matrix[MAX_SIZE][MAX_SIZE];
    int size;
    inputMatrixManually(matrix,size);
    printMatrix(matrix,size);
    cin.get();
    cin.get();
    return 0;
}
