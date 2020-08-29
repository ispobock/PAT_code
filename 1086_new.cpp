#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node{
    int data;
    int id;
    node* lchild;
    node* rchild;
};

int n;

node* getNode(node* root, int id){
    if(root == NULL){
        return NULL;
    }
    if(root->id == id){
        return root;
    }
    node* ans = getNode(root->lchild, id);
    if(ans == NULL){
        ans = getNode(root->rchild, id);
    }
    return ans;
}

int count = 0;
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    count++;
    if(count < n){
        printf(" ");
    }
}

int main(){
    scanf("%d%*c", &n);
    string str;
    int data;
    stack<int> st;
    int id = 1, popId = 0;
    node* root = NULL;
    node* nodeIndex = NULL;
    for(int i = 0; i < 2 * n; i++){
        cin>>str;
        if(str.find("Push") != string::npos){
            scanf("%d", &data);
            st.push(id);
            if(root == NULL){
                root = new node;
                root->data = data;
                root->lchild = root->rchild = NULL;
                root->id = id++;
                nodeIndex = root;
            }
            else{
                if(popId != 0){
                    nodeIndex = getNode(root, popId);
                }
                node* temp = new node;
                temp->data = data;
                temp->lchild = temp->rchild = NULL;
                temp->id = id++;
                if(nodeIndex->lchild == NULL){
                    nodeIndex->lchild = temp;
                }
                else{
                    nodeIndex->rchild = temp;
                }
                nodeIndex = temp;
            }
            popId = 0;
        }
        else{
            popId = st.top();
            st.pop();
        }
    }

    postorder(root);

    return 0;
}