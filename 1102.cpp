#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int lchild;
    int rchild;
}Node[15];

int n;

int index = 0;
void layerorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(index != n - 1){
            printf("%d ", top);
            index++;
        }
        else{
            printf("%d\n", top);
        }
        if(Node[top].rchild != -1){
            q.push(Node[top].rchild);
        }
        if(Node[top].lchild != -1){
            q.push(Node[top].lchild);
        }
    }
}

int count = 0;
void inorder(int root){
    if(root == -1){
        return;
    }
    inorder(Node[root].rchild);
    if(count != n - 1){
        printf("%d ", root);
        count++;
    }else{
        printf("%d", root);
    }
    inorder(Node[root].lchild);
}

int main(){
    scanf("%d", &n);
    char c1, c2;
    int root;
    bool hashTable[15] = {false};
    for(int i = 0; i < n; i++){
        scanf("%*c");
        scanf("%c %c", &c1, &c2);
        if(c1 == '-'){
            Node[i].lchild = -1;
        }else{
            Node[i].lchild = c1 - '0';
            hashTable[Node[i].lchild] = true;
        }
        if(c2 == '-'){
            Node[i].rchild = -1;
        }else{
            Node[i].rchild = c2 - '0';
            hashTable[Node[i].rchild] = true;
        }
    }

    for(int i = 0; i < n; i++){
        if(hashTable[i] == false){
            root = i;
        }
    }

    layerorder(root);
    inorder(root);

    return 0;
}

