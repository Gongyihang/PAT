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
    char key;
    int next;
    bool visited;
};
vector<node> v(100000);//数组和vector内存分配方案不通过，效率和内存方面数组=array>vector，


//测试点1和3：测试index为-1时，会发生什么，坏数据，题目说了address为正数但是为何这里又有坏数据？

int main()
{
    int ch1, ch2, n,index,next;
    scanf("%d %d %d",&ch1,&ch2,&n);

    for (int i = 0; i < n; i++)
    {
        char key;
        scanf("%d %c %d",&index,&key,&next);
        v[index] = {key,next,0};

        //测试测试点1，3
        // if(index = -1)
        // {
        //     printf("-1");
        //     return 0;
        // }

    }

    while (ch1 != -1)
    {
        v[ch1].visited = 1;
        ch1 = v[ch1].next;
    }

    while (ch2 != -1)
    {
        if (v[ch2].visited)
        {
            printf("%05d", ch2);
            return 0;
        }
        else
        {
            ch2 = v[ch2].next;
        }
    }
    printf("-1");

    system("pause");
    return 0;
}