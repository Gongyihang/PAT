#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int hash_name_to_num(string name)
{
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        num = num * 26 + (name[i] - 'A'); //名字都是大写的
    }
    num = num * 10 + (name[3] - '0');
    return num;
}

string hash_num_to_name(int num)
{
    string name;
    string digit = "";
    digit = to_string(num % 10);
    char ch;
    num = num / 10;
    int k = 3;
    while (k != 0)
    {
        k--;
        ch = ('A' + num % 26);
        name += ch;
        num = num / 26;
    }
    string ch1,ch2,ch3;
    ch1 = name[2];
    ch2 = name[1];
    ch3 = name[0];
    name = ch1+ch2+ch3+digit;
    //    reverse(name.begin(), name.end());
    //    name += digit;

    return name;

}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    map<int, set<int>> students;
    string tname;
    int tcourse_n, tcourse_id;
    for (int i = 0; i < N; i++)
    {
        cin >> tname >> tcourse_n;
        int t_num = hash_name_to_num(tname);
        for (int j = 0; j < tcourse_n; j++)
        {
            cin >> tcourse_id;
            students[tcourse_id].insert(t_num);
        }
    }

    for (int i = 1; i < K + 1; i++)
    {
        cout << i << " " << students[i].size() << endl;
        for (auto it = students[i].begin(); it != students[i].end(); it++)
        {
            cout << hash_num_to_name(*it) << endl;
        }
    }

    system("pause");
    return 0;
}