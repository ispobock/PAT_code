#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	int data;
	node* lc;
	node* rc;
	int height; 
};

int get_height(node* root){
	if(root == NULL){
		return 0;
	}
	return root->height;
}

void update(node* root){
	if(root->data > 0){
		root->height = max(get_height(root->rc), get_height(root->lc)) + 1;
	}
	else{
		root->height = max(get_height(root->rc), get_height(root->lc));
	}
}

int balance_factor(node* root){
	return get_height(root->lc) - get_height(root->rc);
}

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lc = NULL;
	root->rc = NULL;
	if(x > 0){
		root->height = 1;
	}
	else{
		root->height = 0;	
	}
	return root;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(abs(x) < abs(root->data)){
		insert(root->lc, x);
		update(root);
	}
	else if(abs(x) > abs(root->data)){
		insert(root->rc, x);
		update(root);
	}
}

bool isRBT = true;
void layer(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(balance_factor(top) != 0){
			isRBT = false;
		}
		if(top->data < 0){
			if(top->lc && top->lc->data < 0) isRBT = false;
			if(top->rc && top->rc->data < 0) isRBT = false;
		}
		if(top->lc != NULL){
			q.push(top->lc);
		}
		if(top->rc != NULL){
			q.push(top->rc);
		}
	}
}

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		isRBT = true;
		scanf("%d", &m);
		node* root = NULL;
		for(int j = 0; j < m; j++){
			int temp;
			scanf("%d", &temp);
			insert(root, temp);
		}
		layer(root);
		if(root->data < 0){
			isRBT = false;
		}
		if(isRBT){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}