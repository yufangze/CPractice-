/*************************************************************************
	> File Name: the_digit_num.c
	> Author: yufangze
	> Mail: 205552151@qq.com
	> Created Time: 2019年04月16日 星期二 19时36分42秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf(" has %d digits\n", printf("%d", n));
    //method 2
    char str[100] = {0};
    printf("%d\n", sprintf(str, "%d", n));
    // method 3
    FILE *fout = fopen("/dev/null", "w");
    printf("%d\n", fprintf(fout, "%d", n));
    return 0;
}
