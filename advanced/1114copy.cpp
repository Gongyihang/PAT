#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

struct person
{
    int id;
    int estate_n = 0;
    int estate_area = 0;
};


vector<person> parent(10001);
vector<person> p(10001);
vector<bool>visit(10000,0);

person find_p(person &x)
{
    if (x.id == parent[x.id].id)
    {
        return x;
    }

    parent[x.id] = find_p(parent[x.id]);
    return parent[x.id];
}

person unionn(person &x, person &y)
{
    person x_t = find_p(x);
    person y_t = find_p(y);

    if (x_t.id != y_t.id)
    {
        if (x_t.id < y_t.id)
        {
            x.estate_n += y.estate_n;
            x.estate_area += y.estate_area;
            parent[y.id] = x;
            return x;
        }
        else
        {

            y.estate_n += x.estate_n;
            y.estate_area += x.estate_area;
            parent[x.id] = y;
            return y;
        }
    }else
    {
        if (x_t.id < y_t.id)
        {
            x_t.estate_n+=y_t.estate_n;
            x_t.estate_area+=y_t.estate_area;
            parent[x_t.id] = x_t;
            return x_t;
        }else
        {
            y_t.estate_n += x_t.estate_n;
            y_t.estate_area += x_t.estate_area;
            parent[y_t.id] = y_t;
            return y_t;
        }
    }

}

int main()
{ //注意id四位数字表示，前面补0

    for (int i = 0; i < 10001; i++)
    {
        parent[i].id = i;
    }

    int N,m;
    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        

    }


/*


10
0010 0011 0012 1 0013 1 100
0014 0015 0009 1 0002 2 300
0008   -1   -1 0      1 1000
0016 0001 0004 1 0017 1 500
0013 0010   -1 0      2 300
0018   -1   -1 1 0019 2 150
0009   -1   -1 3 0020 0021 0014 1 100
0021 0015 0009 0      1 50
0017 0020 0016 2 0022 0023 1 300
0019   -1 0018 3 0022 0023 0024 1 100


10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
*/