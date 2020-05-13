#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person {
    string id = "";
    int in_time = 0;
    int out_time = 0;
};

int main()
{
    int n;
    cin >> n;
    vector<person> p(n);
    for (int i = 0; i < n; i++) {
        int sum_in = 0, sum_out = 0;
        cin >> p[i].id;
        for (int j = 0; j < 3; j++) {
            int t;
            cin >> t;
            sum_in += t * pow(10, 4 - 2 * j);
            if (j != 2)
                getchar();
        }
        p[i].in_time = sum_in;
        for (int j = 0; j < 3; j++) {
            int t;
            cin >> t;
            sum_out += t * pow(10, 4 - 2 * j);
            if (j != 2)
                getchar();
        }
        p[i].out_time = sum_out;
    }

    string unlock_id = p[0].id, lock_id = p[0].id;
    int min_time = p[0].in_time, max_time = p[0].out_time;
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i].in_time < min_time) {
            min_time = p[i].in_time;
            unlock_id = p[i].id;
        }
        if (p[i].out_time > max_time) {
            max_time = p[i].out_time;
            lock_id = p[i].id;
        }
    }
    cout << unlock_id << " " << lock_id;

    return 0;
}