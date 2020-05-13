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
    scanf("%d %d", &N, &M);
    vector<int> v(1001, 0);
    int coin;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &coin);
        v[coin]++;
    }
    int flag = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] != 0 && M > i)
        {
            v[i] -= 1;
            if (v[M - i] > 0)
            {
                printf("%d %d", M - i, i);
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        printf("No Solution");
    }
    system("pause");
    return 0;
}