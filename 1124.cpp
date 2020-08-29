#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int m, n, s;
	scanf("%d %d %d", &m, &n, &s);
	int index = 1;
	set<string> st;
	for(int i = 0; i < m; i++){
		string str;
		cin>>str;
		if(index >= s && (index - s) % n == 0){
			if(st.find(str) != st.end()){
				continue;
			}
			else{
				printf("%s\n", str.c_str());
				st.insert(str);
			}
		}
		index++;
	}
	if(index <= s){
		printf("Keep going...\n");
	}

	return 0;
}