#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("file_1.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Không thể mở file." << endl;
    }

    return 0;
}
