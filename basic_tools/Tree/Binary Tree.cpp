#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

// 动态实现用指针，静态实现用数组
struct node{
    int data;
    int layer;
    node* lchild;
    node* rchild;
};

node* new_node(int v){
    node* Node = (node*)malloc(sizeof(node));
    //node* Node = new node;
    Node->data = v;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

// 搜索并修改
void search(node* root, int x, int new_data){
    // recursion boundry
    if(root == NULL){
        return;
    }
    if(root->data == x){
        root->data = new_data; // 只修改值不用传递引用
    }
    // recursion for two child-trees
    search(root->lchild, x, new_data);
    search(root->rchild, x, new_data);
}

// 先序遍历(DFS)
void preorder(node* root){
    // recursion boundry
    if(root == NULL){
        return;
    }
    printf("%d\n", root->data);
    // recursion, left first
    preorder(root->lchild);
    preorder(root->rchild);
}

// 中序遍历(DFS)
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d\n", root->data);
    inorder(root->rchild);
}

// 后序遍历(DFS)
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n", root->data);
}

// 层序遍历(BFS)
void layerorder(node* root){
    queue<node*> q;
    q.push(root);
    root->layer = 1;
    if(!q.empty()){
        // 取队首元素
        node* now = q.front();
        printf("%d\n", now->data);
        // 队首元素出队
        q.pop();
        // 子节点进队
        if(now->lchild != NULL){
            now->lchild->layer = now->layer + 1;
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild);
        }
    }
}

// 根据先序序列pre[]和中序序列in[]构建二叉树
// 其中先序序列指出根节点元素，中序序列指出左右子树，前提是树中没有元素相同
node* create(int preL, int preR, int inL, int inR){
    // recursion boundry
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    // 计算出左子树节点数
    int numleft = k - inL;
    // 分别左右递归
    root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
    root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
    return root;
}
