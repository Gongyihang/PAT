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
    int N, K;
    scanf("%d %d", &N, &K);

    vector<string> students[25001];//此处分配的大小须读题
    string tname;
    int tcourse_n, tcourse_id;
    for (int i = 0; i < N; i++)
    {
        cin>>tname;
        scanf("%d",&tcourse_n);
        for (int j = 0; j < tcourse_n; j++)
        {
            scanf("%d",&tcourse_id);
            students[tcourse_id].push_back(tname);
        }
    }

    for (int i = 1; i <= K; i++)
    {
        printf("%d %d\n",i,students[i].size());
        sort(students[i].begin(), students[i].end());
        for (auto it = students[i].begin(); it != students[i].end(); it++)
        {
            printf("%s\n",(*it).c_str());
        }
    }

    system("pause");
    return 0;
}