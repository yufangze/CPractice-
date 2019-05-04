/*************************************************************************
	> File Name: my_sqrt.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月04日 星期六 15时42分03秒
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <math.h>

#define TEST_FUNC(func, TIMES) {\
    int b = clock();\
    for (int i = 0; i < TIMES; i++) {\
        double temp = func((double)(1.0 * i));\
    }\
    int e = clock();\
    printf("test %s : %lf s\n", #func, 1.0 * (e - b) / CLOCKS_PER_SEC);\
}

double my_sqrt(double n) {
    #define exp 1e-7
    double head = 0, tail = n, mid;
    while (tail - head > exp) {
        mid = (head + tail) / 2.0;
        if (mid * mid < n) head = mid;
        else tail = mid;
    }
    return head;
}

double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return x * x;
}

double newton_sqrt(double y) {
    #define exp 1e-7
    double x = 0;
    while (fabs(f(x, y)) > exp) {
        x = x - f(x, y) / f_prime(x);
    }
    return x;
}

#define max 10000000

int main() {
    TEST_FUNC(sqrt, max);
    TEST_FUNC(my_sqrt, max);
    TEST_FUNC(newton_sqrt, max);
    return 0;
}
