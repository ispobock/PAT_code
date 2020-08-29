#include <cstdio>
#include <algorithm>
using namespace std;

int a[10010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	double temp = a[0];
	double ans = 0;
	for(int i = 1; i < n; i++){
		ans = (temp + a[i]) / 2.0;
		temp = ans;
	}
	int Ans = (int)ans;
	printf("%d\n", Ans);
	return 0;
}