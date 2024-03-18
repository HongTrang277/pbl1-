#include <bits/stdc++.h>

using namespace std;

float console() {
    float choose;
    do {
        cout << endl;
        cout << "=========== Simple matrix calculator ===========" << endl;
        cout << "|   1. Input matrix manually                    |" << endl;
        cout << "|   2. Read matrix from file                    |" << endl;
        cout << "|   3. Matrices addition                        |" << endl;
        cout << "|   4. Matrices multiplication                  |" << endl;
        cout << "|   5. Permute 2 collumns of a matrix           |" << endl;
        cout << "|   6. Close program                            |" << endl;
        cout << "================================================" << endl;
        cout << "Choose your option: ";
        cin >> choose;

        if (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1))) 
        {
            system("cls");
            cout << endl << "Invalid input!" << endl;
        } 
        else {
            break;
        }
    } while (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1)));
    return choose;
}


int main() {
    float userChoice = console();
    // Handle user choice based on the returned value
    // ...
    return 0;
}
