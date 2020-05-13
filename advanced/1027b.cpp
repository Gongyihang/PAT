#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 1;
    int count = 1;
    int i;
    for (i = 3; sum <= n; i += 2) {
        sum += 2 * i;
        count += 2;
    }
    sum -= 2 * (i - 2);
    count -= 2;

    for (int i = 0; i < 2 * count - 1; i++) {
        //第count - 1行是打印一个“*”的那一行
        for (int j = 0; j < count - 1 - abs(count - 1 - i); j++)
            printf(" ");
        for (int j = 0; j < 2 * abs(count - 1 - i) + 1; j++)
            printf("*");
        printf("\n");
    }

    printf("%d %d\n", count,n - sum);
    system("pause");
    return 0;
}