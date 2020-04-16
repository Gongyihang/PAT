#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void query(string &s, int num, vector<vector<string>> &v) //论引用的重要性
{
    int flag = 0;
    if (num != 3)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j][num + 1] == s)
            {
                flag++;
                cout << v[j][1] << endl;
            }
        }
        if (!flag)
        {
            cout << "Not Found" << endl;
            flag = 0;
        }
    }
    else
    {
        for (int j = 0; j < v.size(); j++)
        {
            // auto x = v[j][4].find(s);
            // if (x != string::npos)
            // {
            //     flag++;
            //     cout << v[j][1] << endl;
            // }
            for (int k = 0; k < v[j][4].size(); k++)
            {
                if (v[j][4][k] != ' ' && (k == 0 || v[j][4][k - 1] == ' '))
                {
                    if (v[j][4].substr(k, s.length()) == s)
                    {
                        flag++;
                        cout << v[j][1] << endl;
                    }
                }
            }
        }
        if (!flag)
        {
            cout << "Not Found" << endl;
            flag = 0;
        }
    }
}

int main()
{
    int N = 0;
    cin >> N;
    getchar();
    vector<vector<string>> v;
    for (int i = 0; i < N; i++)
    {
        vector<string> t(7);
        for (int j = 1; j < 7; j++)
        {
            getline(cin, t[j]);
        }
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int M = 0;
    cin >> M;
    getchar();
    string s = "";
    for (int i = 0; i < M; i++)
    {
        string t_s = "";
        getline(cin, t_s);
        int num = atoi(t_s.substr(0, 1).c_str());
        s = t_s.substr(3);
        cout << t_s << endl;
        switch (num)
        {
            // cout << t_s << endl;//never be executed
        case 1:
            query(s, 1, v);
            break;
        case 2:
            query(s, 2, v);
            break;
        case 3:
            query(s, 3, v);
            break;
        case 4:
            query(s, 4, v);
            break;
        case 5:
            query(s, 5, v);
            break;
        }
    }

    system("pause");
    return 0;
}

// void query(map<string, set<int>> &m, string &str)
// {
//     if (m.find(str) != m.end())
//     {
//         for (auto it = m[str].begin(); it != m[str].end(); it++)
//             printf("%07d\n", *it);
//     }
//     else
//     {
//         cout << "Not Found\n";
//     }
// }

// string s;
// vector<string> v;

// while (cin >> s)
// {
//     v.push_back(s);
//     char c = getchar();
//     if (c == '\n')
//     {
//         break;
//     }
// }
