#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

//第四个测试点太坏了！！！！！

vector<int> vres(100000, 0);
int main()
{

    int ch1, ch2;
    int n;
    cin >> ch1 >> ch2 >> n;

    for (int i = 0; i < n; i++)
    {
        int index, address;
        char ch;
        cin >> index >> ch >> address;
        if (address != -1)  
        {
            vres[address]++;
        }
    }

    int flag = 0,res;
    for (int i = 0; i < 100000; i++)
    {
        if (vres[i] == 1 || vres[i] == 0){
                ;
        }
        else
        {
            flag = 1;
            res = i;
        }
    }

    if (flag)
    {
        printf("%05d\n", res);
    }
    else
    {
        printf("-1\n");
    }

    system("pause");
    return 0;
}


/*
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 00000
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 00000
00001 o 00010

00011 00022 11
00003 i 00002
00010 a 00004
00003 g -1
00004 D 00006
00002 n 00003
00022 B 00005
00011 L 00001
00005 e 00006
00001 o 00010
00001 o 00010
00001 o 00010
*/


