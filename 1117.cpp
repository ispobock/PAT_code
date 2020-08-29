#include <cstdio>
using namespace std;

int mile[100000000] = {0};

int main(){
	int n;
	scanf("%d", &n);
	int max = 0;
	for(int i = 0; i <n; i++){
		int a;
		scanf("%d", &a);
		mile[a]++;
		if(a > max){
			max = a;
		}
	}
	int cnt = 0;
	for(int i = max; i >= 0; i--){
		if(cnt >= i){
			printf("%d\n", i);
			break;
		}
		cnt += mile[i];
	}

	return 0;
}