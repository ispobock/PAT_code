#include <cstdio>
using namespace std;

int pre[50010], in[50010];

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	return root;
}

node* create(int pl, int pr, int inl, int inr){
	if(pl == pr){
		return NULL;
	}
	node* root = newNode(pre[pl]);
	int pos;
	for(int i = inl; i < inr; i++){
		if(in[i] == pre[pl]){
			pos = i;
			break;
		}
	}
	root->lchild = create(pl + 1, pl + pos - inl + 1, inl, pos);
	root->rchild = create(pl + pos - inl + 1, pr, pos + 1, inr);
	return root;
}

bool flag = true;
void postorder(node* root){
	if(root ==  NULL || flag == false){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	if(flag){
		printf("%d\n", root->data);
		flag = false;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	node* root = create(0, n, 0, n);
	postorder(root);
	return 0;
}