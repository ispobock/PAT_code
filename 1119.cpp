#include <cstdio>

int n;

struct node{
	int data;
	node* lc;
	node* rc;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lc = root->rc = NULL;
	return root;
}

int pre[40], post[40];

bool flag = true;
node* create(int preL, int preR, int postL, int postR){
	if(preL > preR){
		return NULL;
	}
	if(preL == preR){
		node* root = newNode(pre[preL]);
		return root;
	}
	node* root = newNode(pre[preL]);
	int pos;
	for(int i = postL; i < postR; i++){
		if(post[i] == pre[preL + 1]){
			pos = i;
		}
	}
	if(pos == postR - 1){
		flag = false;
	}
	
	root->lc = create(preL + 1, preL + pos - postL + 1, postL, pos);
	root->rc = create(preL + pos - postL + 2, preR, pos + 1, postR - 1);
	
	return root;
}

int cnt = 0;
void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->lc);
	printf("%d", root->data);
	cnt++;
	if(cnt < n){
		printf(" ");
	}
	else{
		printf("\n");
	}
	inorder(root->rc);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	if(flag == true){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	inorder(root);
	
	return 0;
}