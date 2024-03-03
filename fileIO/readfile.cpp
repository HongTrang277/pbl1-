#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
using namespace std;


#define MAX 100

bool matrix_reader(string file, int matrix[][MAX], int &size);

int main()
{
    int matrix[MAX][MAX];
    int size;
    if(matrix_reader("file_1.txt", matrix, size))
    {
        cout << "đọc file dc r ae, làm gì làm sau";
    }
    else 
    {
        cout << "Không mở được file/file không tồn tại trong cùng folder";
    }
    return 0;
}
/*
    hàm này đọc ma trận từ file text
    string file: đường dẫn file text
    int matrix[][]: Ma trận 2 chiều sẽ lưu ma trận đọc được, ma trận mặc định truyền theo tham chiếu
    int &size: Kích thước của ma trận, vì là ma trận vuông nên số hàng = số cột. 
    Dùng tham chiếu để biến trong hàm main cũng bị thay đổi

*/
bool matrix_reader(string file, int matrix[][MAX], int &size)
{
    size = -1; // Khởi tạo kích thước ma trận là -1. Tức là chưa biết kích thước
    ifstream whatToRead;
    whatToRead.open(file);
    string line;
    // Đọc lần lượt từng dòng 
    int rows, cols; // Khai báo chỉ số hàng, cột
    // Vòng for này sẽ tăng dần chỉ số hàng
    for(rows = 0; getline( whatToRead, line ); ++rows)
    {
        string element = "";
        cols = 0; // Bắt đầu mỗi hàng, cho chỉ số cột khởi tạo = 0
        for(int t = 0; t < line.length(); ++t)
        {
            if(line[t] != ' ')
            {
                // Nếu ký tự hiện tại khác dấu cách => nối vào biến element
                element += line[t];
            }
            // Nếu ký tự hiện tại là dấu cách, hoặc là ký tự cuối của hàng
            if(line[t] == ' ' || t == line.length() - 1)
            {
                // Thực hiện chuyển string thành số int dùng hàm atoi
                // Hàm atoi nhận vào biến kiểu char*, nên cần dùng .c_str() để chuyển từ string về char*
                matrix[rows][cols] = atoi(element.c_str());
                // Tăng chỉ số cột
                cols++;
                // Đặt lại giá trị element
                element = ""; 
            }
        }
        // Nếu chưa gán giá trị kích thước ma trận thì gán trước.
        // Hiểu luôn là nó lấy số phần tử của hàng đầu tiên làm giá trị khởi tạo cho kích thước ma trận
        if(size == -1) size = cols;
        // Nếu số cột của một hàng bất kỳ khác kích thước => ko phải ma trận vuông
        if(size != cols) return false;
    }
    // Nếu số hàng của ma trận khác kích thước => ko phải ma trận vuông
    if(size != rows) return false;
    whatToRead.close();
    return true;
}