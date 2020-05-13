#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct polynomials {
    int coeff = 0;
    int exp = 0;
};

int main()
{
    double p[1001], coeff;
    for (int i = 0; i < 1001; i++) {
        p[i] = 0;
    }
    int k1, k2, exp;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> exp >> coeff;
        p[exp] += coeff;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> exp >> coeff;
        p[exp] += coeff;
    }
    vector<int> v;
    for (int i = 1000; i >= 0; i--) {
        if (p[i]) {
            v.push_back(i);
        }
    }                  //测试点1,3,4,5是测试是否保留了一位小数，否则无法通过，cout保留一位小数，要增加头文件<iomanip>
    cout << v.size(); //输出的时候注意，如果采用这种方式输出，则测试点6通过没有问题。
    for (int i = 0; i < (int)v.size(); i++) {
        cout << " " << v[i] << " " << fixed<< setprecision(1) <<p[v[i]];
    }

    // if (v.size() == 0) {     //测试点6，最后一个测试点。如果采用if判断最后一个数，这里有个坑。
    //     cout << v.size();
    //     return 0;
    // }
    // cout << v.size() << " "; //输出的时候注意
    // for (int i = 0; i < (int)v.size(); i++) {
    //     if (i != (int)v.size() - 1)
    //         cout << v[i] << " " << fixed << setprecision(1) << p[v[i]] << " ";
    //     else
    //         cout << v[i] << " " << fixed << setprecision(1) << p[v[i]];
    // }
    return 0;
}