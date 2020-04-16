#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

struct node
{
    int self;
    int key;
    int next;
};

vector<node> v(100000);

int main(){
    int head,N,k;
    scanf("%d %d %d",&head,&N,&k);

    for(int i = 0;i < N;i++){
        node t;
        scanf("%d %d %d",&t.self,&t.key,&t.next);
        v[t.self] = t;
    }

    int p = head;
    int q,tem = head,count = 0;
    int newhead = 0;
    while (p != -1)
    {
        count++;
        p = v[p].next;
    }

    while (count >= k)
    {
        int i;
        p = v[tem].next;
        q = v[p].next;
        for(i = 1;i < k;i++){
            v[p].next = v[q].next;
            v[q].next = v[tem].next;
            v[tem].next = q;
            q = v[p].next;
        }
        if (i == 1)
        {
            newhead = q;
        }
        tem = p;
        count = count - k;
    }
    while (newhead != -1)
    {
        printf("%05d %d %5d\n",newhead,v[newhead].key,v[newhead].next);
        newhead = v[newhead].next;
    }
    
    system("pause");
    return 0;
}

/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00001 6 4
00004 4 00005
00001 1 00002
00006 6 -1
00003 3 00004
00005 5 00006
00002 2 00003
*/