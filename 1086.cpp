#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

int n;
vector<string> op;
stack<int> st;
int pre[35], in[35];

int toInt(string s){
    int ans = 0;
    for(string::iterator it = s.begin(); it != s.end(); it++){
        ans = ans * 10 + *it - '0';
    }
    return ans;
}

int prePos, inPos[35] = {0};
void getInorder(vector<string> op){
    int index = 1, pIndex = 1;
    for(int i = 0; i < 2 * n; i++){
        if(op[i].find("Push") != string::npos){
            int num = toInt(op[i].substr(5, op[i].length() - 5));
            prePos = pIndex;
            pre[pIndex++] = num;
            st.push(num);
        }
        else{
            while(inPos[prePos] != 0){
                prePos--;
            }
            inPos[prePos] = index;
            in[index++] = st.top();
            st.pop();
        }
    }
}


node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;
    }
    node* Node = new node;
    Node->data = pre[preL];
    int k;
    k = inPos[preL];
    int Lnum = k - inL;
    Node->lchild = create(preL + 1, preL + Lnum, inL, k - 1);
    Node->rchild = create(preL + Lnum + 1, preR, k + 1, inR);
    return Node;
}

int count = 0;
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    count++;
    if(count < n){
        printf(" ");
    }
}


int main(){
    scanf("%d%*c", &n);
    string str;
    for(int i = 0; i < 2 * n; i++){
        getline(cin, str);
        op.push_back(str);
    }
    getInorder(op);
    /*
    for(int i = 1; i <= n; i++){
        printf("%d ", in[i]);
    }
    printf("\n");
    for(int i = 1; i <= n; i++){
        printf("%d ", pre[i]);
    }
    printf("\n");
    */
    node* root = create(1, n, 1, n);
    postOrder(root);

    return 0;
}