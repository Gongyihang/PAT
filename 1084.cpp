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
    string r;
    getline(cin, r);

    map<char, int> m;

    for (int i = 0; i < r.size(); i++)
    {
        r[i] = toupper(r[i]);
        m[r[i]] = 1;
    }

    vector<char> ch;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
        auto pos = m.find(s[i]);
        if (!(pos == m.end() ? 0 : 1))
        {
            auto tit = find(ch.begin(), ch.end(), s[i]);
            if (tit == ch.end())
            {
                ch.push_back(s[i]);
            }
        }
    }
    for (int i = 0; i < ch.size(); i++)
    {
        cout << ch[i];
    }

    system("pause");
    return 0;
}



