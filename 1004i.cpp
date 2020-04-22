#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v(100);
vector<int> level(100), flag(100, 0);
int max_level = -1;

void bfs()
{
    level[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        if (v[cur].size() == 0) {
            flag[level[cur]]++;
            max_level = max(level[cur], max_level);
        }
        for (int i = 0; i < (int)v[cur].size(); i++) {
            q.push(v[cur][i]);
            level[v[cur][i]] = level[cur] + 1;
        }
        q.pop();
    }
}

int main()
{
    int n, m, child, lenc, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> child >> lenc;
        for (int j = 0; j < lenc; j++) {
            cin >> t;
            v[child].push_back(t);
        }
    }
    bfs();

    for (int i = 1; i <= max_level; i++) {
        if (i != 1)
            cout << " ";
        cout << flag[i];
    }
    system("pause");
    return 0;
}