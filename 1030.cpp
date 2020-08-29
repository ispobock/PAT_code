#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

struct Node{
	string data;
	int lc, rc;
}node[25];

int r;
void postorder(int root){
	if(root == -1){
		return;
	}
	if(root != r && (node[root].lc != -1 || node[root].rc != -1)){
		printf("(");
	}
	postorder(node[root].lc);
	cout<<node[root].data;
	postorder(node[root].rc);
	if(root != r && (node[root].lc != -1 || node[root].rc != -1)){
		printf(")");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int Hash[25] = {false};
	for(int i = 1; i <= n; i++){
		cin>>node[i].data>>node[i].lc>>node[i].rc;
		if(node[i].lc != -1){
			Hash[node[i].lc] = true;
		}
		if(node[i].rc != -1){
			Hash[node[i].rc] = true;
		}
	}
	for(int i = 1; i <= n; i++){
		if(Hash[i] == false){
			r = i;
		}
	}
	postorder(r);

	return 0;
}

