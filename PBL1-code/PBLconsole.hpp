#include <bits/stdc++.h>
#include <fstream>
#include "PBLcalculation.hpp"
#include "PBLmatrix&file.hpp"

using namespace std;

int Continue();
int savechoice();
int savePermit();
void Menu();

void Intro()
{
    system("cls");  
    cout << endl;
        cout << "╔═══════════════╦═══════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║    Group 7    ║                      Đề tài 901                                   ║" << endl;
        cout << "╠═══════════════╝   Tìm nghiệm của hệ phương trình đại số tuyến tính                ║" << endl;
        cout << "║                      bằng phương pháp tự chọn ( Phép khử Gauss )                  ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "╠══════════════════════════════╦════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ║                  Phan Thanh Trường                 ║" << endl;
        cout << "║     Sinh viên thực hiện      ╠════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ║                Nguyễn Thị Hồng Trang               ║" << endl;
        cout << "╠══════════════════════════════╩════════════════════════════════════════════════════╣" << endl;
        cout << "║                              ╔════════════════════╗                               ║" << endl;
        cout << "║                              ║ Mô tả chương trình ║                               ║" << endl;
        cout << "║                              ╚════════════════════╝                               ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "║     - Đọc dữ liệu ma trận từ bàn phím hoặc file                                   ║" << endl;
        cout << "║     - Biến đổi thành ma trận tam giác trên và thể hiện các bước biến đổi          ║" << endl;
        cout << "║     - Giải ma trận tam giác trên bằng quá trình ngược, in ra vecto nghiệm, in ra  ║" << endl;
        cout << "║       đa thức p(x) có các hệ số bằng tổng các cột                                 ║" << endl;
        cout << "║     - Tính Q(x) = Sum (p(xi)) với xi là nghiệm                                    ║" << endl;
        cout << "║     - Lưu các dữ liệu vào file                                                    ║" << endl;
        cout << "║                                                                                   ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════════════════════════════════╝" << endl;
        cin.get();
}

float console() {
    float choose;
    do 
    {
        cout << endl;
        cout << "╔═══════════ Máy tính ma trận đơn giản ══════════╗" << endl;
        cout << "║                                                ║ " << endl;
        cout << "║    1. Nhập ma trận bằng tay                    ║ " << endl;
        cout << "║    2. Đọc ma trận từ file                      ║ " << endl;
        cout << "║    3. Biến đổi ma trận và giải nghiệm          ║ " << endl;
        cout << "║    4. In đa thức P(x) ra màn hình              ║ " << endl;
        cout << "║    5. Tính Q(x)= SUM(p(xi))                    ║ " << endl;
        cout << "║    6. Lưu vào file                             ║ " << endl;
        cout << "║    7. Đóng chương trình                        ║ " << endl;
        cout << "║                                                ║ " << endl;
        cout << "╚════════════════════════════════════════════════╝" << endl;
        cout << "Mời bạn đưa ra lựa chọn: ";
        cin >> choose;
        cin.ignore(1000 , '\n');

        if (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1))) 
        {
            system("cls");
            cout << endl << "Lựa chọn không hợp lệ!" << endl;
        } 
        else {
            break;
        }
    } while (!((choose == static_cast<int>(choose)) && (choose <= 7 && choose >= 1)));
    return choose;
}


void Menu()
{
    int i;
    int size,size1,size2;

	string fileName;

    ofstream filesave;

    float matrix[MAX_SIZE][MAX_SIZE];
	float valid_matrix[MAX_SIZE][MAX_SIZE];
    valid_matrix[0][0]=(float)TRASHVALUE;
	float triangle_matrix[MAX_SIZE][MAX_SIZE];
    triangle_matrix[0][0]=(float)TRASHVALUE;
    float resVector[MAX_SIZE];
    resVector[0]=(float)TRASHVALUE;
    double Qx = (float)TRASHVALUE;
	
    POLYNOMIAL poly = new polynomial;
    zero_polynomial(poly);

    int userChoice;
    int nextstep, preChoice= -1;
    int notStart = 0;

    bool choice[2] = {false,false};
    MENU: 
	system("cls");             
	userChoice = console();
	system("cls");

    switch(userChoice)
    {
        case 1:
        {
            INPUTMANUALLY:
            system("cls");
            if (valid_matrix[0][0] != (float)TRASHVALUE)
            {
                cout << "Đặt lại các giá trị đã tính của ma trận cũ khi nhập vào ma trận mới" << endl;
                valid_matrix[0][0]=(float)TRASHVALUE;
                triangle_matrix[0][0]=(float)TRASHVALUE;
                zero_polynomial(poly);
                resVector[0]=(float)TRASHVALUE;
                choice[0] = choice[1] = 0;
            }
            inputMatrixManually(matrix, size);
            cin.ignore(1000 , '\n');
            SavedValidMatrices(matrix,size,valid_matrix,size1);
            if (valid_matrix[0][0] == (float)TRASHVALUE)
                cout << "Bạn chưa nhập ma trận!" << endl;
            else 
            {
                cout << endl << "Ma trận hệ số :" << endl;
                printMatrix(valid_matrix,size1);
            }
            nextstep = Continue();
            if (nextstep == 2) goto MENU;
            break;
        }
        case 2:
        {
            READFILE:
            system("cls");
            if (valid_matrix[0][0] != (float)TRASHVALUE)
            {
                cout << "Đặt lại các giá trị đã tính của ma trận cũ khi nhập vào ma trận mới" << endl;
                valid_matrix[0][0]=(float)TRASHVALUE;
                triangle_matrix[0][0]=(float)TRASHVALUE;
                zero_polynomial(poly);
                resVector[0]=(float)TRASHVALUE;
                choice[0] = choice[1] = 0;
            }
            cout << "Nhập tên file / đường dẫn trực tiếp chỉ đến file : ";
            getline(cin, fileName);
            switch (matrix_reader(fileName, matrix, size))
            {
                case 0:
                {
                    cout << endl << "Không thể mở file" << endl;
                    break;
                }
                case 1:
                {
                    cout << endl << "Số hàng và cột của ma trận không thỏa kích thước ma trận [n,n+1]" << endl;
                    break;
                }
                case 3:
                {
                    cout << endl << "Hãy chắc chắn ma trận chỉ chứa các số hợp lệ" << endl;
                    break;
                }
                case 2:
                {
                    cout << endl << "Đọc ma trận từ file \"" << fileName << "\" thành công" << endl;
                    SavedValidMatrices(matrix,size,valid_matrix,size1);
                    if (valid_matrix[0][0] == (float)TRASHVALUE)
                        cout << "Bạn chưa nhập gì cả" << endl;
                    else 
                    {
                        cout << endl << "Ma trận hệ số :" << endl;
                        printMatrix(valid_matrix,size1);
                    }
                    break;
                }
            }
            nextstep = Continue();
            if (nextstep == 2) goto MENU;
            break;
        }
        case 3:
        {
            notStart = 0;
            GEI:
            system("cls");
            if (valid_matrix[0][0] == (float)TRASHVALUE)
            {    
                cout << "Thiếu ma trận đầu vào, chương trình sẽ sử dụng ma trận mặc định!" << endl;
                matrix_reader("defaultMat.txt", valid_matrix, size1);
                Sleep(3000);
            }
            size2 = size1;
            TurnIntoTriangleMatrix(valid_matrix,size1, triangle_matrix, size2);
            cout << "Hoàn thành biến đổi bằng phép khử Gauss" << endl;
            if (triangle_matrix[0][0] == (float)(float)TRASHVALUE)
                cout << "Bạn chưa biến đổi ma trận tam giác thành công" << endl;
            else 
            {
                cout << "Ma trận tam giác: " << endl;
                printMatrix(triangle_matrix,size2);
                cout << endl;
            }
            if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
            {
                cout << "Hệ phương trình vô số nghiệm!" << endl;
            }
            else if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                cout << "Hệ phương trình vô nghiệm" << endl;
            else
            {
                cout << "Vector nghiệm :" << endl;
                for (int i =0 ; i <size1; i++ )
                    cout << setw(8) << setprecision(3) << resVector[i] << " ";
                cout << endl;
            }
            Sleep(3000);
            if (notStart--)
            {
                cout << "Nhấn phím Enter để tiếp tục";
                cin.get();
                goto PRINTPOLYNOMIAL;
            }
            nextstep = Continue();
            if (nextstep == 2) goto MENU;
            break;
        }
        // Add code to make it shows the details transformations and shows result
        // case 4:
        // {
        //     notStart = 0;
        //     SolveTriangleMatrix:
        //     system("cls");
        //     if (triangle_matrix[0][0] == (float)TRASHVALUE)
        //     {
        //         cout << "Bạn chưa biến đổi ma trận tam giác để giải" << endl;
        //         notStart++;
        //         Sleep(3000);
        //         goto GEI;
        //     }
        //     else 
        //     {
        //         if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
        //         {
        //             cout << "Hệ phương trình vô số nghiệm!" << endl;
        //         }
        //         else if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
        //             cout << "Hệ phương trình vô nghiệm" << endl;
        //         else
        //         {
        //             cout << "Đã giải ma trận thành công !" << endl;
        //             cout << endl << "Vector nghiệm :" << endl;
        //             for (int i =0 ; i <size1; i++ )
        //                 cout << setw(8) << setprecision(3) << resVector[i] << " ";
        //             cout << endl;
        //         }
        //     }
        //     Sleep(3000);
        //     if (notStart)
        //     {   
        //         cout << "Nhấn phím Enter để tiếp tục";
        //         cin.get();
        //         goto PRINTPOLYNOMIAL;
        //     }
        //     cout << "Nhấn Enter để quay lại Menu" << endl;
        //     cin.ignore(1000 , '\n');
        //     cin.get();
        //     goto MENU;
        //     break;
        // }
        case 4:
        {
            notStart = 0;
            PRINTPOLYNOMIAL:
            system("cls");
            if (valid_matrix[0][0] == (float)TRASHVALUE)
            {    
                cout << "Bạn chưa nhập vào ma trận hợp lệ" << endl;
                notStart++;
                Sleep(3000);
                goto GEI;
            }
            else
            {    
                zero_polynomial(poly);
                for (i =0; i<size1; i++)
                    for (int j=0; j<=size1; j++)
                        poly->coeff_array[j]+=valid_matrix[i][j];
                cout <<"Đa thức P(x):"<<endl;
                display_polynomial(poly,size1); 
                cout << endl;
            }
            Sleep(3000);
            if (notStart--)
            {   
                cout << "Nhấn phím Enter để tiếp tục";
                cin.get();
                goto CalculateQx;
            }
            nextstep = Continue();
            if (nextstep == 2) goto MENU;
            break;
        }
        case 5:
        {
            notStart = 0;
            CalculateQx:
            system("cls");
            Qx = 0;
            if (resVector[0] == (float)TRASHVALUE)
            {
                if (triangle_matrix[0][0] != (float)TRASHVALUE)
                {
                    if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                        cout << "Hệ phương trình vô nghiệm , không thể tính!" << endl;
                    else if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                        cout << "Hệ phương trình có vô số nghiệm , không thể tính!" << endl;
                }
                else
                {    
                    cout << "Bạn chưa tính đa thức P(x)" << endl;
                    notStart++;
                    Sleep(3000);
                    goto PRINTPOLYNOMIAL;
                }
            }
            else
            {
                for (i = size1-1; i>=0; i--)
                {
                    Qx += CalculatePx(poly,resVector[i]);
                }
                cout << "Kết quả khi tính Q(x) = SUM(P(xi)) với i=(1,n) :" << endl;
                cout << fixed << setw(15) << setprecision(3) << Qx << endl;
            }
            cout << "Nhấn Enter để quay lại Menu" << endl;
            cin.ignore(1000 , '\n');
            cin.get();
            goto MENU;
            break;
        }
        case 6:
        {
            userChoice=-1;
            while (userChoice)
            {
                system("cls");
                cout << "╔═══════════════════════════════════════════╗" << endl;
                cout << "║                Lưu vào file               ║" << endl;
                cout << "╠═══════════════════════════════╦═══════════╣" << endl;
                cout << "║ 1.Giải phương trình và nghiệm ║   ";
                if (choice[0]) 
                cout << "Đã lưu" ;
                else cout << "      ";
                cout <<"  ║"<< endl;
                cout << "╠═══════════════════════════════╬═══════════╣" << endl;
                cout << "║ 2.Xử lí số liệu của ma trận   ║   ";
                if (choice[1]) 
                cout << "Đã lưu" ;
                else cout << "      ";
                cout <<"  ║"<< endl;
                cout << "╚═══════════════════════════════╩═══════════╝" << endl;
                cout << "Nhập lựa chọn: ";
                userChoice = savechoice();
                switch (userChoice)
                {
                    case 1:
                    {
                        if (resVector[0] == (float)TRASHVALUE)
                        {   
                            if (triangle_matrix[0][0]==(float)TRASHVALUE)
                            {
                                if (valid_matrix[0][0]==(float)TRASHVALUE)
                                    cout << endl << "Chưa nhập ma trận mới để lưu, không thể tự động lưu ma trận mặc định" << endl;
                                cout << endl << "Chưa biến đổi ma trận và giải nghiệm" << endl;
                            }
                            else 
                            {
                                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                                {
                                    saveMatrixToFile(valid_matrix,size1,"result.txt",0);
                                    saveMatrixToFile(triangle_matrix,size2,"result.txt",1);
                                    filesave.open("result.txt", ios :: out | ios :: app);
                                    filesave << endl << "Hệ phương trình vô số nghiệm" << endl;
                                    filesave.close();
                                    choice[0]=true;
                                }
                                if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                                {
                                    saveMatrixToFile(valid_matrix,size1,"result.txt",0);
                                    saveMatrixToFile(triangle_matrix,size2,"result.txt",1);
                                    filesave.open("result.txt", ios :: out | ios :: app);
                                    filesave << endl << "Hệ phương trình vô nghiệm" << endl;
                                    filesave.close();
                                    choice[0]=true;
                                }
                            }
                        }
                        else
                        {
                            saveMatrixToFile(valid_matrix,size1,"result.txt",0);
                            saveMatrixToFile(triangle_matrix,size2,"result.txt",1);
                            savepoly_resToFile(poly, resVector, size1, "result.txt",3);
                            choice[0]=true;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (Qx == 0)
                        {
                            if (poly->high_power == 0)
                            {
                                if (triangle_matrix[0][0]==(float)TRASHVALUE)
                                {
                                    if (valid_matrix[0][0]==(float)TRASHVALUE)
                                        cout << endl << "Chưa nhập ma trận để xử lí số liệu, không sử dụng số liệu từ ma trận mặc định" << endl;
                                    cout << endl << "Chưa biến đổi ma trận và giải nghiệm" << endl;
                                }
                            }
                            else 
                                {
                                    if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 0)
                                    {
                                        savepoly_resToFile(poly, resVector, size1, "result.txt",2);
                                        filesave.open("result.txt", ios :: out | ios :: app);
                                        filesave << endl << "Không có nghiệm để tính Q(x)" << endl;
                                        filesave.close();
                                        choice[1]=true;
                                    }
                                    if (SolveTriangleMatrix(triangle_matrix, size2,resVector) == 2)
                                    {
                                        savepoly_resToFile(poly, resVector, size1, "result.txt",2);
                                        filesave.open("result.txt", ios :: out | ios :: app);
                                        filesave << endl << "Không có nghiệm để tính Q(x)" << endl;
                                        filesave.close();
                                        choice[1]=true;
                                    }
                                }
                        }
                        else
                        {
                            if (Qx != (float)TRASHVALUE)
                            {   
                                savepoly_resToFile(poly, resVector, size1, "result.txt",2);
                                savepoly_resToFile(poly, resVector, size1, "result.txt",3); 
                                choice[1]=true;
                            }
                            else 
                                cout << "Chưa tính Q(x)";
                        }
                        break;
                    }
                    default:
                        goto MENU;
                }
                cin.ignore(1000 , '\n');
            }
        }
        default:
            break;
    }
    cout << "Chương trình kết thúc!";

}

int Continue() 
{
	cout << endl << "Nhập b để quay lại menu!" ;
    cout << endl << "Nhập phím bất kỳ để kết thúc chương trình!" << endl << "Nhập : ";
	char input;
    input = getchar();
    cin.ignore(1000 , '\n');
	if (input == 'b')
		return 2;
    return 0;
}

int savechoice() 
{
	cout << endl << "Nhập 1 để lưu lựa chọn 1!" << endl << "Nhập 2 để lưu lựa chọn 2!" ;
    cout << endl << "Nhập phím bất kỳ để quay về menu!" << endl << "Nhập : ";
	char input;
    input = getchar();
    cin.ignore(1000 , '\n');
	if (input == '1')
		return 1;
	if (input == '2')
		return 2;
    return 0;
}

int savePermit()
{
    cout << " Do you want to save to file ? ";
    cout << endl << "Press y for \"Yes\"" << endl << "Press n or any key for \"No\" " ;
	char input;
    input = getchar();
    cin.ignore(1000 , '\n');
	if (input == 'y')
		return 1;
    return 0;
}