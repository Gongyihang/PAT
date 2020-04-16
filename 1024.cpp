#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;
//是回文数返回1，不是回文数返回0
bool is_palindromic(string num)
{
    string s_num = num;
    string t = s_num;
    reverse(s_num.begin(), s_num.end());
    if (s_num == t)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string add(string a, string b)
{
    int flag = 0;
    string res = "";
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int t = a[i] - '0' + b[i] - '0' + flag;
        int g = t % 10;
        res += to_string(g);
        flag = t / 10;
    }
    if (flag)
    {
        res += to_string(flag);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string num;
    int k;
    cin >> num >> k;
    int t = k;
    string res = num;
    while (!is_palindromic(res) && k)
    {
        string rev_res = res;
        reverse(rev_res.begin(), rev_res.end());
        res = add(res, rev_res);
        k--;
    }

    cout << res << endl
         << t - k;

    system("pause");
    return 0;
}