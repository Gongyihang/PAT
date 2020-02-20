#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        string s1, s2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '&')
            {
                s1 = s.substr(0, i);
                s2 = s.substr(i + 1);
            }
        }
        reverse(s2.begin(), s2.end());
        if (s1 == s2)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    system("pause");
    return 0;
}