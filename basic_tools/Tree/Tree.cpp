#include <queue>
#include <vector>
using namespace std;

const int maxn = 50;

struct node{
    int data;
    vector<int> child; // 用vector存放子节点数组下标
}Node[maxn];

// 先根遍历
void preorder(int root){
    printf("%d", Node[root].data);
    for(int i = 0; i < Node[root].child.size(); i++){
        preorder(Node[root].child[i]);
    }
}

// 层序遍历
void layerorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        node now = Node[q.front()];
        q.pop();
        printf("%d", now.data);
        for(int i = 0; i < now.child.size(); i++){
            q.push(now.child[i]);
        }
    }
}