#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[25];

struct node{
    int data;
    int height;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int get_height(node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int get_balance_factor(node* root){
    if(root == NULL){
        return 0;
    }
    return get_height(root->lchild) - get_height(root->rchild);
}

void update_height(node* root){
    root->height = max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

void insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }
    if(v < root->data){
        insert(root->lchild, v);
        update_height(root);
        if(get_balance_factor(root) == 2){
            if(get_balance_factor(root->lchild) == 1){
                R(root);
            }
            else{
                L(root->lchild);
                R(root);
            }
        }
    }
    else{
        insert(root->rchild, v);
        update_height(root);
        if(get_balance_factor(root) == -2){
            if(get_balance_factor(root->rchild) == -1){
                L(root);
            }
            else{
                R(root->rchild);
                L(root);
            }
        }
    }
}

node* create(int a[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, a[i]);
    }
    return root;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    node* root = create(a, n);
    printf("%d", root->data);
    return 0;
}