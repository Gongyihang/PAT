#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int course_n, stu_n;
    map<char *, set<int>> course;
    char *tname;
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &course_n, &stu_n);
        for (int j = 0; j < stu_n; j++)
        {
            scanf("%s", &tname);
            course[tname].insert(course_n);
        }
    }
    char *tquery_name;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &tquery_name);
        printf("%s %d", &tquery_name, course[tquery_name].size());
        for (auto it = course[tquery_name].begin(); it != course[tquery_name].end(); it++)
        {
            printf(" %d", *it);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}