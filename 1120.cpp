#include <cstdio>
#include <set>
using namespace std;

int cal(int n){
	int ans = 0;
	while(n != 0){
		ans += n % 10;
		n = n / 10;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	set<int> st;
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		st.insert(cal(temp));
	}
	printf("%d\n", st.size());
	int cnt = 0;
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		printf("%d", *it);
		cnt++;
		if(cnt < st.size()){
			printf(" ");
		}
	}

	return 0;
}