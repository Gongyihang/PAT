#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <sstream>
using namespace std;

string marsN[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string marsM[13] = {" ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

// map<string,int> m = {};

int main()
{
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s);
        if ('0' <= s[0] && s[0] <= '9')
        {
            stringstream ss;
            string res = "";
            int num;
            ss << s;
            ss >> num;
            if (num > 13 && num % 13 != 0)
            {
                string ts1 = marsN[num % 13];
                num /= 13;
                string ts2 = marsM[num % 13];
                res = ts2 + " " + ts1;
                cout << res << endl;
            }
            else if (num < 13)
            {
                string ts = marsN[num % 13];
                cout << ts << endl;
            }
            else if (num % 13 == 0)
            {
                cout << marsM[num / 13] << endl;
            }
        }
        else
        {
            if (s.size() <= 4)
            {
                for (int i = 0; i < 13; i++)
                {
                    if (s == marsN[i])
                    {
                        cout << i << endl;
                        break;
                    }
                }
                for (int i = 0; i < 13; i++)
                {
                    if (s == marsM[i])
                    {
                        cout << i * 13 << endl;
                        break;
                    }
                }
            }
            else
            {
                string str1 = s.substr(0, 3); //十位
                string str2 = s.substr(4, 3); //个位
                int num = 0;
                for (int i = 0; i < 13; i++)
                {
                    if (str2 == marsN[i])
                    {
                        num = i;
                    }
                }
                for (int i = 0; i < 13; i++)
                {
                    if (str1 == marsM[i])
                    {
                        num += i * 13;
                        cout << num << endl;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}