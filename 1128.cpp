#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int n;
		scanf("%d", &n);
		int a[1010];
		for(int j = 0; j < n; j++){
			scanf("%d", &a[j]);
		}
		bool flag = true;
		for(int j = 0; j < n; j++){
			for(int l = j + 1; l < n; l++){
				if(l - j == abs(a[l] - a[j]) || a[l] == a[j] || a[l] > n || a[l] < 1){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}