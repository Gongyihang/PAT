#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA
{
    int id, fid, mid, num, area;
    int cid[10];
} data[1005];
struct node
{
    int id, people;
    double num, area;
    bool flag = false;
} ans[10000];
int father[10000];
bool visit[10000];
int find(int x)
{
    while (x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b)
{
    int faA = find(a);
    int faB = find(b);
    if (faA > faB)
        father[faA] = faB;
    else if (faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b)
{
    if (a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main()
{
    int n, k, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < 10000; i++)
        father[i] = i;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if (data[i].fid != -1)
        {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if (data[i].mid != -1)
        {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for (int i = 0; i < n; i++)
    {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (visit[i])
            ans[find(i)].people++;
        if (ans[i].flag)
            cnt++;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (ans[i].flag)
        {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}



/*


10
0010 0011 0012 1 0013 1 100
0014 0015 0009 1 0002 2 300
0008   -1   -1 0      1 1000
0016 0001 0004 1 0017 1 500
0013 0010   -1 0      2 300
0018   -1   -1 1 0019 2 150
0009   -1   -1 3 0020 0021 0014 1 100
0021 0015 0009 0      1 50
0017 0020 0016 2 0022 0023 1 300
0019   -1 0018 3 0022 0023 0024 1 100


10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
*/