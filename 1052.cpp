#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node{
    int add;
    int key;
    int next;
    int falg;
}node[maxn];

bool cmp(Node a, Node b){
    if(a.falg == -1 || b.falg == -1){
        return a.falg > b.falg;
    }
    else{
        return a.key < b.key;
    }
}

int main(){
    for(int i = 0; i < maxn; i++){
        node[i].falg = -1;
    }
    int n, head;
    scanf("%d %d", &n, &head);
    int add, temp, next;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &add, &temp, &next);
        node[add].add = add;
        node[add].key = temp;
        node[add].next = next;
    }

    int p = head, count = 0;
    while(p != -1){
        node[p].falg = 1;
        count++;
        p = node[p].next;
    }

    if(count == 0){
        printf("0 -1"); // 特判
    }
    else{
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].add);
        for(int i = 0; i < count - 1; i++){
            printf("%05d %d %05d\n", node[i].add, node[i].key, node[i + 1].add);
        }
        printf("%05d %d -1", node[count - 1].add, node[count - 1].key);
    }

    return 0;
}