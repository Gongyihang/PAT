#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string num;
    cin >> num;
    long long sum = 0;
    string s[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 0; i < (int)num.size(); i++) {
        sum += num[i] - '0';
    }
    string res = to_string(sum);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << s[res[i] - '0'];
        if (i != (int)res.size() - 1) {
            cout << " ";
        }
    }

    system("pause");
    return 0;
}