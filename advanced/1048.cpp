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

    vector<int> v;
    int coin;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &coin);
        v.push_back(coin);
    }

    sort(v.begin(), v.end());

    int v1 = 0, v2 = 0;

    int flag = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (!flag)
        {
            for (int j = 0; j < N; j++)
            {
                v2 = v[i];
                if (v[j] == (M - v2) && j < i)
                {
                    v1 = v[j];
                    printf("%d %d\n", v1, v2);
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    if (!flag)
    {
        printf("No Solution");
    }

    system("pause");
    return 0;
}