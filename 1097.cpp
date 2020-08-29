#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node{
    int add;
    int data;
    int next;
    int flag;
}node[maxn];

bool cmp(Node a, Node b){
    return a.flag < b.flag;
}

bool hash_table[10010] = {false};

int main(){
    for(int i = 0; i < maxn; i++){
        node[i].flag = maxn;
    }

    int begin, n;
    scanf("%d %d", &begin, &n);
    for(int i = 0; i < n; i++){
        int add;
        scanf("%d", &add);
        scanf("%d %d", &node[add].data, &node[add].next);
        node[add].add = add;
    }

    int p = begin, count1 = 0, count2 = 0;
    queue<int> q;
    while(p != -1){
        if(hash_table[abs(node[p].data)] == false){
            hash_table[abs(node[p].data)] = true;
            node[p].flag = count1++;
        }
        else{
            count2++;
            q.push(p); //巧用队列
        }
        p = node[p].next;
    }

    int order = 0;
    while(!q.empty()){
        node[q.front()].flag = count1 + order;
        order++;
        q.pop();
    }

    sort(node, node + maxn, cmp);
    for(int i = 0; i < count1 - 1; i++){
        printf("%05d %d %05d\n", node[i].add, node[i].data, node[i + 1].add);
    }
    printf("%05d %d -1\n", node[count1 - 1].add, node[count1 - 1].data);
    for(int i = count1; i < count1 + count2 - 1; i++){
        printf("%05d %d %05d\n", node[i].add, node[i].data, node[i + 1].add);
    }
    if(count2 >= 1){
        printf("%05d %d -1\n", node[count1 + count2 - 1].add, node[count1 + count2 - 1].data);
    }
    
    
    return 0;
}