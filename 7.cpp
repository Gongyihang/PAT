#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int a[10001];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int l, r, k;
        int count = 0;
        cin >> l >> r >> k;
        for (int j = l; j <= r; j++)
        {
            if (a[j] < a[k])
            {
                count++;
            }
        }

        if (count == (k - l))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}