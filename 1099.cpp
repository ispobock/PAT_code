#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int data;
    int lchild;
    int rchild;
}Node[105];

int n, a[105];

int index = 0;
void inorder(int root){
    if(root == -1){
        return;
    }
    inorder(Node[root].lchild);
    Node[root].data = a[index++];
    inorder(Node[root].rchild);
}

int num = 0;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        printf("%d", Node[top].data);
        num++;
        if(num < n){
            printf(" ");
        }
        if(Node[top].lchild != -1){
            q.push(Node[top].lchild);
        }
        if(Node[top].rchild != -1){
            q.push(Node[top].rchild);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &Node[i].lchild, &Node[i].rchild);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    inorder(0);
    BFS(0);

    return 0;
}