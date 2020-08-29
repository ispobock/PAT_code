#include <cstdio>
#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;

map<string, int> mp;
set<string> st;

bool isPrime(int a){
	for(int i = 2; i * i <= a; i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		string str;
		cin>>str;
		mp[str] = i;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		string query;
		cin>>query;
		if(mp.find(query) != mp.end() && st.find(query) == st.end()){
			st.insert(query);
			if(mp[query] == 1){
				printf("%s: Mystery Award\n", query.c_str());
			}
			else if(isPrime(mp[query])){
				printf("%s: Minion\n", query.c_str());
			}
			else{
				printf("%s: Chocolate\n", query.c_str());
			}
		}
		else if(mp.find(query) != mp.end() && st.find(query) != st.end()){
			printf("%s: Checked\n", query.c_str());
		}
		else{
			printf("%s: Are you kidding?\n", query.c_str());
		}
	}
	return 0;
}