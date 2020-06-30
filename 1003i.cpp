#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


/*

AAPAATAAAA
0123456789

p=2,t=5
a=2,b=2,c=4

a * b == c
p * (t - p - 1) == s.size() - t - 1

*/

int main()
{
    int n;
    cin >> n;
    string s;
    int p = 0, t = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < (int)s.size(); j++) {
            m[s[j]]++;
            if (s[j] == 'P')
                p = j;
            if (s[j] == 'T')
                t = j;
        }

        if (m.size() == 3 && m['P'] == 1 && m['T'] == 1 && m['A'] != 0 && (t - p) != 1 && p * (t - p - 1) == s.size() - t - 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    system("pause");
    return 0;
}