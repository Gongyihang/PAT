#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

string muti(string &num)
{
    string res = "";
    int flag = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int t = (num[i] - '0') * 2;
        int g = t % 10;
        res += to_string(g + flag);
        flag = t / 10;
    }
    if (flag)
    {
        res += "1";
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> query(10, 0);

    string num;
    cin >> num;
    for (int i = 0; i < num.size(); i++)
    {
        query[num[i] - '0']++;
    }

    string doublenum = muti(num);

    for (int i = 0; i < doublenum.size(); i++)
    {
        query[doublenum[i] - '0']--;
    }

    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (query[i] == 0)
        {
            flag++;
        }
    }

    if (flag == 10)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << doublenum << endl;
    system("pause");
    return 0;
}