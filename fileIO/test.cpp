#include <bits/stdc++.h> 
#include <fstream>
#include "consoleLib.hpp"

using namespace std;

#define MAX_SIZE 100
void Menu()
{
    float matrix1[MAX_SIZE][MAX_SIZE];
    matrix1[0][0]=(float)TRASHVALUE;
    system("cls");             
	int userChoice = console();
    system("cls");

    switch(userChoice)
    {
        case 3:
        {
            if (matrix1[0][0] == (float)TRASHVALUE)
                cout << "Lack of input matrix, requires input!" << endl;
        }

    }
}
int main()
{
    Menu();
    return 0;
}