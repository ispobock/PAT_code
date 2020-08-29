#include <cstdio>
#include <set>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int temp;
	set<int> st;
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		st.insert(temp);
	}
	for(int i = 1; i < 10000000000; i++){
		if(st.find(i) != st.end()){
			continue;
		}
		else{
			printf("%d", i);
			break;
		}
	}
	return 0;
}