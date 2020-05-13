#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string subs;
    getline(cin, subs);

    string res;

    int i = 0;
    while (i < s.size())
    {
        if (subs.find(s[i]) != s.npos)//注意复习
        {
            i++;
        }
        else
        {
            res += s[i];
            i++;
        }
    }
    cout << res;

    system("pause");
    return 0;
}