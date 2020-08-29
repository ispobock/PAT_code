#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int s1 = 0, s2 = 0;
	for(int i = 0; i < n / 2; i++){
		s1 += a[i];
	}
	for(int i = n / 2; i < n; i++){
		s2 += a[i];
	}
	if(n % 2 == 0){
		printf("0 %d\n", s2 - s1);
	}
	else if(n % 2 == 1){
		printf("1 %d\n", s2 - s1);
	}


	return 0;
}