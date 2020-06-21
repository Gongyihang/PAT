#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    //此处s[4]设定为4位的原因是，题目给了输入数据n是小于10的100次方的
    //10的100次方就是10后面跟着100个0，也就是所得的和最大值为101个9，
    //其最大和应该为99*101=1899，不会超过4位数
    char ch, s[4];
    char zidian[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    //getchar()接收的是键盘输入的一个字符串，以回车一次读取字符串中的每一个字符
    //并且会自动返回显示在屏幕上
    while ((ch = getchar()) != '\n') {
        sum += (ch - '0');
    }
    sprintf(s, "%d", sum); //将sum转换为字符数组s，相当于tostring的思路
    for (int i = 0; s[i] != '\0'; i++) { //遍历到字符数组的末尾，末尾以'\0'为结束
        if (i > 0)
            printf(" ");
        printf("%s", zidian[s[i] - '0']);
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        sum += s[i] - '0';
    }
    string res = to_string(sum);
    char zidian[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    for (int i = 0; i < (int)res.size() - 1; i++) {
        cout << zidian[res[i] - '0'] << " ";
    }
    cout << zidian[res[res.size() - 1] - '0'];
    system("pause");
    return 0;
}