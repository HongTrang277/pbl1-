#include <bits/stdc++.h>
using namespace std;

#define e 0.001

float f(float x);

int daycung(float f(float), float a, float b, float &res)
{
    if (f(a) * f(b) > 0) return 0; //case sai khoang nghiem

    res = a - ((b - a) * f(a)) / (f(b) - f(a));

    if (f(res) * f(a) < 0) {
        while (abs(res - b) > e) {
            b = res;
            res = a - ((b - a) * f(a)) / (f(b) - f(a));
        }
    }
    else 
    {
        while (abs(res - a) > e) {
            a = res;
            res = a - ((b - a) * f(a)) / (f(b) - f(a));
        }
    }
    return 1;
}

float f(float x)
{
    return exp(x) - 10 * x + 7;
}

