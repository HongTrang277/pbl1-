#include <stdio.h>
int main() {
    char a, b, c;
    scanf(" %c %c %c", &a, &b, &c);
    int nut = 0;
    int bienc = 1;
    switch (a) {
        case 'A' : nut +=1; break;
        case '2' : nut +=2; break;
        case '3' : nut +=3; break;
        case '4' : nut +=4; break;
        case '5' : nut +=5; break;
        case '6' : nut +=6; break;
        case '7' : nut +=7; break;
        case '8' : nut +=8; break;
        case '9' : nut +=9; break;
        case '0': nut +=10; break;
        case 'J' : nut +=10; break;
        case 'Q' : nut +=10; break;
        case 'K' : nut +=10; break;
        default: bienc = 0;
            }
    switch (b) {
        case 'A' : nut +=1; break;
        case '2' : nut +=2; break;
        case '3' : nut +=3; break;
        case '4' : nut +=4; break;
        case '5' : nut +=5; break;
        case '6' : nut +=6; break;
        case '7' : nut +=7; break;
        case '8' : nut +=8; break;
        case '9' : nut +=9; break;
        case '0': nut +=10; break;
        case 'J' : nut +=10; break;
        case 'Q' : nut +=10; break;
        case 'K' : nut +=10; break;
        default: bienc = 0;
            }
    switch (c) {
        case 'A' : nut +=1; break;
        case '2' : nut +=2; break;
        case '3' : nut +=3; break;
        case '4' : nut +=4; break;
        case '5' : nut +=5; break;
        case '6' : nut +=6; break;
        case '7' : nut +=7; break;
        case '8' : nut +=8; break;
        case '9' : nut +=9; break;
        case '0': nut +=10; break;
        case 'J' : nut +=10; break;
        case 'Q' : nut +=10; break;
        case 'K' : nut +=10; break;
        default: bienc = 0;
        }
        if ( bienc ) {
            int diem = nut % 10;
            printf("%d",diem); }
        else { printf("dữ liệu không hợp lệ";)}
        return 0;
}