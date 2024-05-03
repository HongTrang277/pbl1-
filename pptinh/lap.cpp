#include <bits/stdc++.h>
using namespace std;

#define e 0.001

float f(float x);
float g(float x);

int lap(float f(float), float g(float), float a, float b, float &res)
{
    if (f(a) * f(b) > 0)
        return 0; // case sai khoảng nghiệm
    if (f(a) * f((a + b) / 2) < 0)
        res = a;
    else
        res = b;
    
    do 
    {
        a = res;
        res = g(res);
    }
    while(abs(a - res) > e);

    return 1;
}

float f(float x)
{
    return pow(x, 3) - x -1;
}

float g(float x) 
{
    return pow(x + 1, 1.0 / 3);
}
