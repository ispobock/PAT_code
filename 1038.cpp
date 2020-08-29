#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	return a+b < b+a;
}

int main(){
	int n;
	string ans[10010];
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		cin >> ans[i];
	}

	sort(ans, ans+n, cmp);

	for(int i = 1; i<n; i++){
		ans[0] += ans[i];
	}

	while(ans[0][0] == '0'){
		ans[0].erase(ans[0].begin());
	}

	if(ans[0].length() == 0){
		printf("0\n");
	}
	else{
		cout << ans[0] << endl;
	}


	return 0;
}