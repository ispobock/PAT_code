#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int n;

struct node{
	int data;
	node* lc;
	node* rc;
	int height;

};

void update(node* root){
	if(root->lc == NULL && root->rc != NULL){
		root->height = root->rc->height + 1;
	}
	else if(root->rc == NULL && root->lc != NULL){
		root->height = root->lc->height + 1;
	}
	else if(root->lc != NULL && root->rc != NULL){
		root->height = max(root->lc->height, root->rc->height) + 1;
	}
	else{
		root->height = 1;
	}
}

int balance_factor(node* root){
	if(root->lc == NULL && root->rc != NULL){
		return -1 * root->rc->height;
	}
	else if(root->rc == NULL && root->lc != NULL){
		return root->lc->height;
	}
	else if(root->lc != NULL && root->rc != NULL){
		return root->lc->height - root->rc->height;
	}
	else{
		return 0;
	}
}

void LR(node* &root){
	node* temp = root->rc;
	root->rc = root->rc->lc;
	temp->lc = root;
	update(root);
	update(temp);
	root = temp;
}

void RR(node* &root){
	node* temp = root->lc;
	root->lc = root->lc->rc;
	temp->rc = root;
	update(root);
	update(temp);
	root = temp;
}

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lc = root->rc = NULL;
	root->height = 1;
	return root;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x <root->data){
		insert(root->lc, x);
		update(root);
		if(balance_factor(root) > 1 && balance_factor(root->lc) == 1){
			RR(root);
		}
		else if(balance_factor(root) > 1 && balance_factor(root->lc) == -1){
			LR(root->lc);
			RR(root);
		}
		else if(balance_factor(root) < -1 && balance_factor(root->rc) == 1){
			RR(root->rc);
			LR(root);
		}
		else if(balance_factor(root) < -1 && balance_factor(root->rc) == -1){
			LR(root);
		}
	}
	else{
		insert(root->rc, x);
		update(root);
		if(balance_factor(root) > 1 && balance_factor(root->lc) == 1){
			RR(root);
		}
		else if(balance_factor(root) > 1 && balance_factor(root->lc) == -1){
			LR(root->lc);
			RR(root);
		}
		else if(balance_factor(root) < -1 && balance_factor(root->rc) == 1){
			RR(root->rc);
			LR(root);
		}
		else if(balance_factor(root) < -1 && balance_factor(root->rc) == -1){
			LR(root);
		}
	}
}

int cnt = 0;
map<int, int> mp;
int num = 0;
bool flag = true;
void layer(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		printf("%d", top->data);
		cnt++;
		mp[cnt] = top->data;
		if(cnt < n){
			printf(" ");
		}
		else{
			printf("\n");
		}
		if(top->lc == NULL || (top->lc != NULL && top->rc == NULL) || (top->lc == NULL && top->rc == NULL)){
			if(top->lc != NULL && top->rc == NULL && flag){
				num++;
			}
			flag = false;
		}
		if(top->lc != NULL){
			q.push(top->lc);
			if(flag == true){
				num++;
			}
		}
		if(top->rc != NULL){
			q.push(top->rc);
			if(flag == true){
				num++;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}
	layer(root);

	if(num == n - 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}