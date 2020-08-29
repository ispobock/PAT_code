#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Node{
    int add;
    int data;
    int next;
    int flag;
}node[maxn];

bool cmp1(Node a, Node b){
    if(a.flag == -1 || b.flag == -1){
        return a.flag > b.flag;
    }
    else{
        return a.flag < b.flag;
    }
}

bool cmp2(Node a, Node b){
    if(a.flag == -1 || b.flag == -1){
        return a.flag > b.flag;
    }
    else{
        return a.flag > b.flag;
    }
}

int main(){
    for(int i = 0; i < maxn; i++){
        node[i].flag = -1;
    }

    int begin, n, k;
    scanf("%d %d %d", &begin, &n, &k);
    int address;
    for(int i = 0; i < n; i++){
        scanf("%d", &address);
        scanf("%d %d", &node[address].data, &node[address].next);
        node[address].add = address;
    }

    int p = begin;
    int num = 0;
    while(p != -1){
        node[p].flag = num++;
        p = node[p].next;
    }

    sort(node, node + maxn, cmp1);

    Node* temp = node;
    while(temp + k <= node + num){ // 此处需小心界限
        sort(temp, temp + k, cmp2);
        temp = temp + k;
    }

    for(int j = 0; j < num - 1; j++){
        printf("%05d %d %05d\n", node[j].add, node[j].data, node[j + 1].add);
    }
    printf("%05d %d -1\n", node[num - 1].add, node[num - 1].data);

    return 0;
}