#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;
vector<int> parent(10001,0);
vector<int> isrooot(10001,0);


int findf(int x){
    if(x == parent[x]){
        return x;
    }
    parent[x] = findf(parent[x]);
    return parent[x];
}

void unionn(int x,int y){
    int a = findf(x);
    int b = findf(y);

    if (a != b)
    {
        parent[a] = b;
    }    
}

int main(){
    for(int i = 0;i < 10001;i++){
        parent[i] = i;
    }

    int N;
    scanf("%d",&N);
        vector<int> visit(10001);

    for(int i = 0;i < N;i++){
        int m,bird1;

        scanf("%d %d",&m,&bird1);
        visit[bird1] = 1;
        for(int j = 0;j < m-1;j++){
            int bird2;
            scanf("%d",&bird2);
            unionn(bird1,bird2);
            visit[bird2] = 1;
        }
    }

    vector<int> count(10001,0);//保存鸟的数量

    for(int i = 0;i < 10001;i++){
        if(visit[i] == 1){
            count[findf(i)]++;
        }
    }

    int num_of_tree = 0,num_of_bird = 0;

    for(int i = 0;i < 10001;i++){
        if (count[i] != 0 && visit[i] == 1)
        {
            num_of_tree++;
            num_of_bird+=count[i];
        }
    }

    int qurey_n;
    scanf("%d",&qurey_n);

    vector<string> res;

    for(int i = 0;i < qurey_n;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        if(findf(t1) == findf(t2)){
            res.push_back("Yes");
        }else
        {
            res.push_back("No");
        }
        
    }
    printf("%d %d\n",num_of_tree,num_of_bird);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}