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
    int N, M;
    scanf("%d", &N);

    vector<set<int>> v;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &M);
        set<int> tset;
        for (int j = 0; j < M; j++)
        {
            int num;
            scanf("%d", &num);
            tset.insert(num);
        }
        v.push_back(tset);
    }
    int n;
    scanf("%d", &n);

    float res;
    for (int i = 0; i < n; i++)
    {
        int set1, set2;
        scanf("%d %d", &set1, &set2);
        set1--;
        set2--;

        int Nc = 0, Nt = v[set2].size();//Nt的初值为第二个set的长度
        for (auto it = v[set1].begin(); it != v[set1].end(); it++)
        {
            if (v[set2].find(*it) != v[set2].end())
            {
                Nc++;
            }
            else{
                Nt++;
            }
        }
        //下面Nt计算方法超时
        // set<int> copy = v[set1];
        // copy.insert(v[set2].begin(), v[set2].end());
        // Nt = copy.size();
        res = Nc * (1.0) / Nt;
        printf("%.1f%%\n", res*100);
    }

    system("pause");
    return 0;
}