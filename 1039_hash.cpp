#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
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

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int course_n, stu_n;
    map<int, set<int>> course;
    string tname;
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &course_n, &stu_n);
        for (int j = 0; j < stu_n; j++)
        {
            cin >> tname;
            int num = hash_name_to_num(tname);
            course[num].insert(course_n);
        }
    }
    string tquery_name;
    for (int i = 0; i < N; i++)
    {
        cin >> tquery_name;
        int num = hash_name_to_num(tquery_name);
        cout << tquery_name << " " << course[num].size();
        for (auto it = course[num].begin(); it != course[num].end(); it++)
        {
            printf(" %d", *it);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}