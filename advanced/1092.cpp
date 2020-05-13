#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string taget;
    getline(cin,taget);

    map<char,int> m;
    for(int i = 0;i < s.size();i++){
        m[s[i]]++;
    }
    for(int i = 0;i < taget.size();i++){
        m[taget[i]]--;
    }

    int extra = 0;
    int miss = 0;
    bool flag = 0;
    for(auto it = m.begin();it != m.end();it++){
        if (it->second < 0)
        {
            flag = 1;
            miss += (-it->second);
        }else
        {
            extra+=it->second;
        }
    }
    if (flag)
    {
        printf("No %d",miss);
    }else
    {
        printf("Yes %d",extra);
    }
    
    

    system("pause");
    return 0;
}