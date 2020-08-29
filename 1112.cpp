#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<char, int> mp;
set<char> notbroken;

int main(){
	int k;
	scanf("%d", &k);
	string str;
	cin>>str;
	int cnt = 0;
	char pre = 'A';
	for(string::iterator it = str.begin(); it != str.end(); it++){
		mp[*it] = 0;
		if(*it == pre){
			cnt++;
		}
		else{
			if(pre != 'A' && mp[pre] == 0){
				notbroken.insert(pre);
			}
			pre = *it;
			cnt = 1;
		}
		if(cnt == k){
			pre = 'A';
			cnt = 0;
			if(notbroken.find(*it) == notbroken.end()){
				mp[*it] = 1;
			}
		}
	}
	string ans;
	cnt = 0;
	map<char, bool> check;
	for(string::iterator it = str.begin(); it != str.end(); it++){
		if(mp[*it] == 0){
			ans += *it;
		}
		else if(mp[*it] == 1){
			if(cnt != 0){
				cnt--;
			}
			else{
				ans += *it;
				cnt = k - 1;
				if(check.find(*it) == check.end()){
					printf("%c", *it);
					check[*it] = true;
				}
			}
		}
	}

	printf("\n%s\n", ans.c_str());
	
	return 0;
}