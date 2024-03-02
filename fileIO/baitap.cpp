#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100

void readMatrixFromFile(string filename, float matrix[MAX][MAX], int rows, int cols) {
	ifstream file(filename);
	if(file.is_open()) {
		file >> rows >>cols;
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				file >> matrix[i][j];
			}
		}
	}
	else cout<< "can't open file" <<endl;
}


void printMatrix(float a[MAX][MAX], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			cout<< a[i][j] << " ";
		}
		cout<<endl;
	}
}

void saveMatrixToFile(int matrix[][MAX], int rows, int cols, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout<< "can't open file" <<endl;
        return;
    } else {
		file << rows << " " << cols << endl;
		for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
            file << matrix[i][j] << " ";
        	}
        file << endl;
    	}
    file.close();
}

void tichMaTran(float a[][100], float b[][100], int n,int m, int m1) {
	float c[MAX][MAX];
	int i, j, k;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int tt=0;
			for(int k=0; k<m1; k++) { 
				tt=a[i][k]*b[k][i]; 
			}
			c[i][j]= tt;
		}
	}
}

void maTranTong ( float a[][MAX], float b[][MAX], int m, int m1) {
    float c[MAX][MAX];
	int i, j, k;
	for(int i=0; i<m; i++) {
		for(int j=0; j<m; j++) {
				c[i][j]=a[i][j]+b[i][j];
			}
		}
	}

void swapCols(float a[][100], int aRow, int aCol, int row1, int row2)
{
    int iaRow, iaCol;
    int tmp;
 
    if (row1 < 0 || row1 >= aRow ||
        row2 < 0 || row2 >= aRow ||
        row1 == row2)
    {
        return;
    }
 
    for (iaCol = 0; iaCol < aCol; iaCol++)
    {
        tmp = a[row1][iaCol];
        a[row1][iaCol] = a[row2][iaCol];
        a[row2][iaCol] = tmp;
    }
}



int main()
{
	int rows1, cols1;
	int rows2, cols2;

	float matrix1[MAX][MAX];
	float matrix2[MAX][MAX];

	readMatrixFromFile("file_1.txt", matrix1, rows1, cols1);
	readMatrixFromFile("file_1.txt", matrix1, rows1, cols1);


	ifstream input("C:\\Users\\minhh\\OneDrive\\Desktop\\input.txt");
	fstream output;
	output.open("C:\\Users\\minhh\\OneDrive\\Desktop\\output.txt", ios::out );
	string str;
	input>>str; // lấy giá trị biến str từ file input
	cout<<str; // in str ra màn hình console
	output<<"Hello world"; //in Hello world vào file output
	input.close(); //đóng file input
	output.close(); //đóng file output
	return 0;
}
