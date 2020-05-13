#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string s = to_string(c);
    bool flag = s[0] == '-' ? 1 : 0;
    int count = 0;
    if (flag) {
        for (int i = (int)s.size() - 1; i > 0; i--) {
            count++;
            if (i != (int)s.size() - 1 && i != 1 && count % 3 == 0) {
                s.insert(i, ",");
            }
        }
    } else {
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            count++;
            if (i != (int)s.size() - 1 && i != 0 && count % 3 == 0) {
                s.insert(i, ",");
            }
        }
    }
    cout << s;
    system("pause");
    return 0;
}