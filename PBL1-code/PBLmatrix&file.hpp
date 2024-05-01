#include <bits/stdc++.h>
#include <fstream>

#define MAX_SIZE 100
#define TRASHVALUE 12345.6789

using namespace std;

int matrix_reader(string file, float matrix[][MAX_SIZE], int &size);
void inputMatrixManually(float matrix[][MAX_SIZE], int &size);
void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
void saveMatrixToFile(float result[][MAX_SIZE], int size, string filename, int preChoice, int col1, int col2);
int SavedValidMatrices(float matrix1[][MAX_SIZE],int &size1,float target_matrix[][MAX_SIZE],int &size2);

/*
    hàm này đọc ma trận từ file text
    string file: tên file text tồn tại trong cùng folder
    int matrix[][]: Ma trận 2 chiều sẽ lưu ma trận đọc được, ma trận mặc định truyền theo tham chiếu
    int &size: Kích thước của ma trận, vì là ma trận vuông nên số hàng = số cột. 
    Dùng tham chiếu để biến trong hàm main cũng bị thay đổi
    Case return 0: lỗi không đọc được file
    Case return 1: Lỗi ma trận không hợp lệ
    Case return 2: Đọc ma trận thành công
*/
int matrix_reader(string file, float matrix[][MAX_SIZE], int &size)
{
    size = -1; // Khởi tạo kích thước ma trận là -1. Tức là chưa biết kích thước
    ifstream whatToRead;
    whatToRead.open(file);
    if (whatToRead.fail())
        return 0;
    string line;
    int dotCount=0;
    int rows, cols;
    for(rows = 0; getline( whatToRead, line ); ++rows)
    {
        string element = "";
        cols = 0;
        for(int t = 0; t < line.length(); ++t)
        {
            // Nếu là chữ thì không hợp lệ
            if ((line[t] >= 'a' && line[t]<= 'z') || (line[t]>= 'A' && line[t]<= 'Z'))
                return 1;
            // Đếm số dấu chấm của số thập phân
            if (line[t] == '.')
            {
                dotCount ++;
                if (dotCount > 1 )
                    return 1;
            }
            // Nếu không phải dấu cách thì nối vào element
            if (line[t] != ' ')
            {
                element += line[t];
            }
            if (line[t] == ' ' || t == line.length() - 1)
            {
                // Hàm atof nhận vào biến kiểu char* và chuyển về kiểu double, nên cần dùng .c_str() để chuyển từ string về char*
                matrix[rows][cols] = static_cast<float>(atof(element.c_str()));
                cols++;
                // Đặt lại giá trị element
                element = ""; 
                // Đặt lại giá trị dotCount
                dotCount=0;
            }
        }
        // Nếu chưa gán giá trị kích thước ma trận thì gán trước.
        // lấy số phần tử của hàng đầu tiên làm giá trị khởi tạo cho kích thước ma trận
        if(size == -1) size = cols-1;
        // Nếu số cột của một hàng bất kỳ khác số ẩn + 1 => không hợp lệ
        if(size != cols-1) return 1;
    }
    // Nếu số hàng của ma trận khác số ẩn => không hợp lệ
    if(size != rows) return 1;
    whatToRead.close();
    return 2;
}

void saveMatrixToFile(float matrix[][MAX_SIZE], int size, string filename, int preChoice, int col1, int col2) 
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
                file << endl << "Linear matrix equation:" << endl; // Lưu ma trận hệ số tuyến tính vào file
                break;
            }
            case 1:
            {
                file << endl << "Upper triangle matrix:" << endl; // Ma trận tam giác trên
                break;            
            }
        }
		for (int i = 0; i < size; ++i) 
		{
        	for (int j = 0; j < size+1; ++j) 
            file << setw(8) << setprecision(3) << matrix[i][j];
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
        for (int j = 0 ; j < size + 1; j++)
            cin >> matrix[i][j];
}

void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size) 
{
	for (int i=0; i<size; i++) 
	{
		for(int j=0; j<size + 1; j++) 
			cout << setw(8) << setprecision(3) << matrix[i][j];
		cout<<endl;
	}
}

int SavedValidMatrices(float matrix1[][MAX_SIZE],int &size1,float target_matrix[][MAX_SIZE],int &size2)
{
    int i, j;
    if (matrix1[0][0] != (float)TRASHVALUE)
	{
        size2= size1;
        for(i=0; i<size2; i++) 
        {
            for(j=0; j<size2; j++) 
                target_matrix[i][j] = matrix1[i][j];
        }
        return 1; // Lưu ma trận thành công
    }
    return 0; // không có ma trận 1
}