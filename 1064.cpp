#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

int n;
int a[10010];

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

int pow(int a, int b){
    int ans = 1;
    for(int i = 0; i < b; i++){
        ans *= a;
    }
    return ans;
}

int compute(int n){
    if(n == 1){
        return 0;
    }
    else{
        int m = 1;
        while(n >= pow(2, m) - 1){
            m++;
        }
        if(n - (pow(2, m - 1) - 1) < pow(2, m - 2)){
            return n - (pow(2, m - 1) - 1) + (pow(2, m - 1) - 2) / 2;
        }
        else{
            return pow(2, m - 2) + (pow(2, m - 1) - 2) / 2;
        }
    }
}

int index = 0;
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        printf("%d", top->data);
        index++;
        if(index < n){
            printf(" ");
        }
        if(top->lchild != NULL){
            q.push(top->lchild);
        }
        if(top->rchild != NULL){
            q.push(top->rchild);
        }
    }
}

node* create(int left, int right){
    if(left > right){
        return NULL;
    }
    int pos = compute(right - left + 1);
    int root_value = a[left + pos];
    node* root = newNode(root_value);
    root->lchild = create(left, left + pos - 1);
    root->rchild = create(left + pos + 1, right);
    return root;
}

int main(){
    scanf("%d", &n);
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    node* root = create(0, n - 1);
    BFS(root);
    return 0;
}