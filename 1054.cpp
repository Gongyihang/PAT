#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

//签到题

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    map<int, int> pix;

    int maxpix = 0;
    int p;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tpix;
            scanf("%d", &tpix);
            pix[tpix]++;
            if (pix[tpix] > maxpix)
            {
                maxpix = pix[tpix];
                p = tpix;
            }
        }
    }
    printf("%d", p);

    system("pause");
    return 0;
}