//AVL树(平衡二叉树)是BST(二叉搜索树)的一种
//其每个结点左右子树的高度相差不过1，因此达到最优搜索算法复杂度logn(以2为底)
struct node{
    int v; //权值
    int hegiht; //当前子树高度
    node* lchild;
    node* rchild;
};

node* new_node(int v){
    node* Node = new node;
    Node->v = v;
    Node->hegiht = 1; //新的节点子树高度均为1
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int get_height(node* root){
    if(root == NULL){
        return 0;
    }
    return root->hegiht;
}

//计算平衡因子
int get_balance_factor(node* root){
    return get_height(root->lchild) - get_height(root->rchild);
}

//更新hegiht
void update_height(node* root){ //因为改的是地址指向的值，故不必传引用
    root->hegiht = max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

//左旋
void L(node* &root){ //改变地址，故传地址的引用
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

//右旋
void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    root = temp;
}


//插入结点，需要判断是否失衡
void insert(node* &root, int v){
    if(root == NULL){
        root = new_node(v);
        return;
    }
    if(v < root->v){
        insert(root->lchild, v);
        update_height(root);
        if(get_balance_factor(root) == 2){
            if(get_balance_factor(root->lchild) == 1){
                R(root); //右旋
            }else{ //get_balance_factor(root->lchild) == -1
                L(root->lchild); //先左旋再右旋
                R(root);
            }
        }
    }else{
        insert(root->rchild, v);
        update_height(root);
        if(get_balance_factor(root) == -2){
            if(get_balance_factor(root->rchild) == -1){
                L(root);
            }else{
                R(root->rchild);
                L(root);
            }
        }
    }
}

//AVL树的建立
node* create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}

