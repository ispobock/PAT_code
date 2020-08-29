#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int in[35], post[35];

struct node{
	int data;
	node* lc;
	node* rc;
};

node* create(int inL, int inR, int postL, int postR){
	if(inL > inR){
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	root->lc = root->rc = NULL;
	int pos;
	for(int i = inL; i <= inR; i++){
		if(in[i] == post[postR]){
			pos = i;
			break;
		}
	}
	root->lc = create(inL, pos - 1, postL, postL + pos - inL - 1);
	root->rc = create(pos + 1, inR, postL + pos - inL, postR - 1);
	return root;
}

int cnt = 0;
int n;

void zig(node* root){
	queue<node*> q;
	stack<node*> st;
	stack<node*> st2;
 	st.push(root);
	int flag = 0;
	while(!q.empty() || !st.empty() || !st2.empty()){
		while(!st.empty()){
			node* top = st.top();
			st.pop();
			cnt++;
			if(flag == 0){
				if(top->lc != NULL){
					q.push(top->lc);
				}
				if(top->rc != NULL){
					q.push(top->rc);
				}
			}
			else{
				if(top->rc != NULL){
					st2.push(top->rc);
				}
				if(top->lc != NULL){
					st2.push(top->lc);
				}
			}
			printf("%d", top->data);
			if(cnt < n){
				printf(" ");
			}
			else{
				printf("\n");
			}
			flag = 1;
		}
		while(!q.empty()){
			node* top = q.front();
			q.pop();
			cnt++;
			if(top->lc != NULL){
				st.push(top->lc);
			}
			if(top->rc != NULL){
				st.push(top->rc);
			}
			printf("%d", top->data);
			if(cnt < n){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
		while(!st2.empty()){
			node* top = st2.top();
			st2.pop();
			cnt++;
			if(top->lc != NULL){
				st.push(top->lc);
			}
			if(top->rc != NULL){
				st.push(top->rc);
			}
			printf("%d", top->data);
			if(cnt < n){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	node* r = create(0, n - 1, 0, n - 1);
	zig(r);

	return 0;
}