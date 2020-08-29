#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> v;

struct node{
	int data;
	node* lc;
	node* rc;
	int layer;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lc = root->rc = NULL;
	return root;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x <= root->data){
		insert(root->lc, x);
	}
	else{
		insert(root->rc, x);
	}
}

void bfs(node* root){
	queue<node*> q;
	root->layer = 0;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(v.size() <= top->layer){
			v.push_back(1);
		}
		else{
			v[top->layer]++;
		}
		if(top->lc != NULL){
			top->lc->layer = top->layer + 1;
			q.push(top->lc);
		}
		if(top->rc != NULL){
			top->rc->layer = top->layer + 1;
			q.push(top->rc);
		}
	}
	
}

int main(){
	int N;
	scanf("%d", &N);
	node* root = NULL;
	for(int i = 0; i < N; i++){
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}
	bfs(root);
	if(v.size())
	printf("%d + %d = %d\n", v[v.size() - 1], v[v.size() - 2], v[v.size() - 1] + v[v.size() - 2]);

	return 0;
}