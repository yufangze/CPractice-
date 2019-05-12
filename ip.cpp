/*************************************************************************
	> File Name: ip.cpp
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2019年01月12日 星期六 10时23分39秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
union IP{
    struct {
       unsigned char arr[4]; 
    } ip;
    unsigned int num;
};

int main(int argc, char *argv[]) {
    IP ip[4] = {0};
    /*while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        scanf("%d.%d")
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }*/
    printf("argc = %d, argv[%d] = %s\n", argc , argc, *(argv + argc - 1));
    if (argc != 4) {
        perror("argc\n");
        exit(1);
    }
    for (int j = 1; j < argc; j++) {
        int temp = 0, a = 0;
        for (int i = 0; argv[j][i]; i++) {
            if (argv[j][i] == '.') continue;
            a = a * 10 + (argv[j][i] - '0');
            if (argv[j][i + 1] == '.' || argv[j][i + 1] == '\0') {
                ip[j - 1].ip.arr[temp++] = a;
                //printf("a = %d\n", a);
                a = 0;
                continue;
            }
        }
    }
    int ip1 = ip[0].num & ip[2].num;
    int ip2 = ip[1].num & ip[2].num;
    if (ip1 == ip2) {
        printf("yes!\n");
    } else {
        printf("no!\n");
    }
    /*for (int i = 0; i < argc - 1; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", ip[i].ip.arr[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", ip[i].num);
    }
    printf("ip1 = %d, ip2 = %d\n", ip1, ip2);
    printf("ip[1] = %d\n", (int)ip[1].ip.arr[3]);
    */
    return 0;
}
