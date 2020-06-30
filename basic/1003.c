#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//@一航代码
/*
算法具体实现：
先从键盘键入你要判断的字符串的个数：用scanf，string_num接收
定义一个字符数组，为字符数组分配空间char*始终是4个字节
char** string = malloc(string_number*sizeof(char *));
比如输入了 "PAT" "PAAT"
这样我们就可以通过string[0]来访问"PAT"

定义的judge函数传入的是*str = string[0]
然后我们可以用str[0]来访问"PAT"中的'P'
进行判断。
*/
int judgt(char* str)
{
    int i = 1;
    int length = strlen(str);
    if (str[0] == 'P') { //this  case is PAT
        while (i != (length - 1)) { //if begin is
            if (str[i++] != 'A') //then this string must
                return 0; // p(n A)T
        }
        if (i == 1 || str[i] != 'T')
            return 0;
        else
            return 1;

    } else if (str[0] == 'A') { //this case is aP..A..T case
        int a = 1;
        int b = 0;
        int c = 0;
        while (str[i] == 'A') { //process a,get prefix A
            a++;
            i++;
        }

        if (str[i++] != 'P') //P
            return 0;

        while (str[i] == 'A') { //process b,get infix A
            b++;
            i++;
        }

        if (str[i++] != 'T')
            return 0;

        c = a * b;
        int j = 0;
        while (str[i] == 'A') {
            j++;
            i++;
        }
        if (j != c)
            return 0;
        else
            return 1;
    } else
        return 0;
}
int main()
{
    int string_number = 0;
    scanf("%d", &string_number);
    int i = 0;
    //为这个字符串数组分配空间
    char** string = malloc(string_number * sizeof(char*));
    for (i = 0; i < string_number; i++){//字符串数组中的每个元素分配空间比如"PAAAAAAAAAAAAT"
        string[i] = malloc(100 * sizeof(char));
    }
    //i初始化 后面要键入字符串数组中的每个元素了，光标要移动到最前端
    i = 0;
    while (i != string_number) {
        scanf("%s", string[i]);
        i++;
    }
    //i初始化 后面要对字符串数组中的每个元素了进行judge，光标要移动到最前端
    i = 0;
    int result = 0;
    while (i != string_number) {
        result = judgt(string[i]);
        if (result == 1)
            printf("YES\n");
        else
            printf("NO\n");
        i++;
    }
    return 0;
}