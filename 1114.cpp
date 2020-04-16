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
    int father;
    int mather;
    int estate_n = 0;
    int estate_area = 0;
};

vector<int> parent(10000,0);
vector<person> p;
vector<bool>visit(10000,0);


int findf(int x){
    if(x ==  parent[x]){
        return x;
    }

    parent[x] = findf(parent[x]);
    return parent[x];
}

void unionn(int x,int y){
    int a = findf(x);
    int b = findf(y);
    if(a < b){
        parent[b] = a;
    }else{              //这个 else是否有问题
        parent[a] = b;
    }
}

int main(){
    
    //初始化parent数组
    for(int i = 0;i < 10000;i++){
        parent[i] = i;
    }

    int N, m;
    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        scanf("%d %d %d %d",&p[i].id,&p[i].father,&p[i].mather,&m);
        visit[p[i].id] = 1;
        if (p[i].father!=-1)
        {
            visit[p[i].father] = 1;
            unionn(p[i].id,p[i].father);
        }
        if (p[i].mather!=-1)
        {
            visit[p[i].mather] = 1;
            unionn(p[i].id,p[i].mather);
        }
        for(int j = 0;j < m;j++){
            person child;
            scanf("%d",&child.id);
            visit[child.id] = 1;
            unionn(p[i].id,child.id);
        }

        scanf("%d %d",&p[i].estate_n,&p[i].estate_area);
    }
    system("pause");
    return 0;
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