/*************************************************************************
	> File Name: str_in_out.c
	> Author: yufangze
	> Mail: 205552151@qq.com
	> Created Time: 2019年04月16日 星期二 20时46分38秒
 ************************************************************************/
#include <stdio.h>

int main() {
    char str[100] = {0};
    scanf("%[^\n]s", str);
    getchar();
    int ret = printf("%s", str);
    printf(" has %d digits\n", ret);
    return 0;
}
