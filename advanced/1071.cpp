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
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    map<string, int> m;
    int tm = 0;
    string ms;

    int i = 0, j = 0;
    while (j < s.size() && i < s.size())
    {
        if (!(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z')))
        {
            i++;
            j = i;
        }
        j++;
        if (!(('0' <= s[j] && s[j] <= '9') || ('a' <= s[j] && s[j] <= 'z')))
        {
            string ts = s.substr(i, j - i);
            m[ts]++;
            if (m[ts] > tm)
            {
                tm = m[ts];
                ms = ts;
            }
            i = j + 1;
        }
    }
    cout << ms << " " << tm;
    system("pause");
    return 0;
}