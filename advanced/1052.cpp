#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

struct node
{
    int self;
    int key;
    int next;
};

int cmp(node a, node b)
{
    return a.key < b.key;
}

vector<node> v(100000);

int main()
{
    int n, head;
    scanf("%d %d", &n, &head);

    if (head == -1)
    {
        printf("0 -1\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int self, key, next;
        scanf("%d %d %d", &self, &key, &next);
        v[self] = {self, key, next};
    }

    vector<node> res;
    while (head != -1)
    {
        res.push_back(v[head]);
        head = v[head].next;
    }

    sort(res.begin(), res.end(), cmp);
    printf("%d %05d\n", res.size(), res.front().self);//测试点4测试头结点的格式是否正确，前面补0
    for (int i = 0; i < res.size() - 1; i++)
    {
        printf("%05d %d %05d\n", res[i].self, res[i].key, res[i + 1].self);
    }
    printf("%05d %d -1\n", res.back().self, res.back().key);
    system("pause");
    return 0;
}