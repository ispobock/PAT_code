#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
using namespace std;


struct Node{
	int id;
	int lc;
	int rc;
}node[25];

int change(string s){
	int ans = 0;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		ans = ans * 10 + (*it - '0');
	}
	return ans;
}

bool Hash[25] = {false};

int last = 0;
bool isCBT(int root){
	queue<int> q;
	q.push(root);
	bool flag = false;
	bool iscbt = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(node[top].lc != -1 && flag == true) iscbt = false;
		if(node[top].lc != -1){
			q.push(node[top].lc);
		}
		else{
			flag = true;
		}
		if(node[top].rc != -1 && flag == true) iscbt = false;
		if(node[top].rc != -1){
			q.push(node[top].rc);
		}
		else{
			flag = true;
		}
		if(q.empty()){
			last = top;
		}
	}
	return iscbt;
}

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		node[i].id = i;
		string str1, str2;
		cin>>str1>>str2;
		if(str1[0] == '-'){
			node[i].lc = -1;
		}
		else{
			int lc = change(str1);
			node[i].lc = lc;
			Hash[lc] = true;
		}
		if(str2[0] == '-'){
			node[i].rc = -1;
		}
		else{
			int rc = change(str2);
			node[i].rc = rc;
			Hash[rc] = true;
		}
	}
	int root;
	for(int i = 0; i < n; i++){
		if(Hash[i] == false) root = i;
	}

	if(isCBT(root)){
		printf("YES %d\n", last);
	}
	else{
		printf("NO %d\n", root);
	}


	return 0;
}