#include <cstdio>

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

void search(node* root, int x){
    if(root == NULL){
        return;
    }
    if(x == root->data){
        printf("%d\n", root->data);
    }else if(x < root->data){
        search(root->lchild, x);
    }else{
        search(root->rchild, x);
    }
}

void insert(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(x == root->data){
        return;        
    }else if(x < root->data){
        insert(root->lchild, x);
    }else{
        insert(root->rchild, x);   
    }
}

node* create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}

// BST节点的删除
// 找前驱
node* findMax(node* root){
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;
}
// 找后继
node* findMin(node* root){
    while(root->lchild != NULL){
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root, int x){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        if(root->lchild == NULL && root->rchild == NULL){
            root = NULL;
        }else if(root->lchild != NULL){
            node* pre = findMax(root->lchild);
            root->data = pre->data; // 以前驱取代root
            deleteNode(root->lchild, pre->data);
        }else{
            node* next = findMin(root->rchild);
            root->data = next->data; // 以后继取代root
            deleteNode(root->rchild, next->data);
        }
    }else if(root->data > x){
        deleteNode(root->lchild, x);
    }else{
        deleteNode(root->rchild, x);
    }
}