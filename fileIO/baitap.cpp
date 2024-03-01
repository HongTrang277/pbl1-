#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
	
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
