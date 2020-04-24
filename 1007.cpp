#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= 0)
            flag = true;
    }
    if (!flag) {
        cout << "0 " << v[0] << " "<< v[n - 1];
        return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > dp[index]) {
            index = i;
        }
    }

    int max_sum = dp[index], start;
    for (start = index; start >= 0; start--) {
        max_sum -= v[start];
        if (!max_sum)
            break;
    }

    cout << dp[index] <<" "<< v[start] <<" "<< v[index];
    return 0;
}