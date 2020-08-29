#include <cstdio>
#include <queue>
using namespace std;

int post[35], in[35];

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* create(int postL, int postR, int inL, int inR){
    if(postL > postR){
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){
            break;
        }
    }
    int numleft = k - inL;
    root->lchild = create(postL, postL + numleft - 1, inL, k - 1);
    root->rchild = create(postL + numleft, postR - 1, k + 1, inR);
    return root;
}

vector<int> vi;

void layerorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        vi.push_back(now->data);
        q.pop();
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    layerorder(root);
    for(int i = 0; i < n; i++){
        printf("%d", vi[i]);
        if(i != n - 1){
            printf(" ");
        }
    }

    return 0;
}