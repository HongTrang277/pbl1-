#include <stdio.h>
#include <math.h>

#define e 0.001

float f(float x);
float fdh1(float x); // fdh1(x) là đạo hàm cấp 1 của hàm f(x)
float fdh2(float x); // fdh2(x) là đạo hàm cấp 2 của hàm f(x)

int TiepTuyen(float f(float), float fdh1(float), float fdh2(float), float a, float b, float &res) {
    if (f(a) * f(b) > 0) return 0; //Sai khoảng nghiệm
    if (f(res) * fdh2(res) < 0) return 1;//Case không thỏa định lý điều kiện đủ
    do {
        a = res;
        res = a - (f(a) * 1.0 / fdh1(a));
    } while (abs(a - res) > e);
    return 2; // Case có nghiệm
}

float f(float x)
{
    return pow(x, 3) + x - 5;
}

float fdh1(float x) 
{
    return 3 * pow(x, 2) + 1;
}

float fdh2(float x) 
{
    return 6 * x;
}
