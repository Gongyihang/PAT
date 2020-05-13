#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);

    map<int,vector<int>> m;

    for(int i = 0;i < N;i++){
        int K;
        scanf("%d:",&K);
        for(int j = 0;j < K;j++){
            int t;
            scanf("%d",&t);
            m[i].push_back(t);
        }
    }
    system("pause");
    return 0;
}