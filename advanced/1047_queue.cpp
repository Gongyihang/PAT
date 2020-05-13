#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
using namespace std;


const int maxk = 2502;
priority_queue<string, vector<string>, greater<string>> pq[maxk];
///使用优先队列数组，每一门课程对应一个优先队列，输入的过程中保存，输入完接着输出即可

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i)
    {
        char s[10];
        int d;
        scanf("%s%d", s, &d);
        string str(s); ///字符数组转为字符串，如果直接按string输入会超时
        while (d--)
        {
            int t;
            scanf("%d", &t);
            pq[t].push(str);
        }
    }
    for (int i = 1; i <= K; ++i)
    {
        printf("%d %d\n", i, pq[i].size());
        while (!pq[i].empty())
        {
            char s[10];
            strcpy(s, pq[i].top().c_str());
            printf("%s\n", s);
            pq[i].pop();
        }
    }
    return 0;
}
