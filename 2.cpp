#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            printf(" ");
        }
        for (int k = i; k > 0; k--)
        {
            printf("* ");
        }
        cout << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("* ");
        }
        cout << endl;
    }
    system("pause");
    return 0;
}