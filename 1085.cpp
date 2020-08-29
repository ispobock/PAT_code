#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

int bs(LL a[], int p, int pos, int n){
	int mid, left = pos, right = n - 1;
	if(a[n - 1] <= (LL)a[pos]*p){
		return n;
	}
	while(left < right){
		mid = (left + right) / 2;
		if(a[mid] <= (LL)a[pos]*p){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return left;
}

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	LL a[100010];
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a+n);
	
	int maxn = 0;
	int l = 0;
	for(int i = 0; i < n; i++){
		l = bs(a, p, i, n) - i;
		if(l > maxn){
			maxn = l;
		}
	}

	printf("%d\n", maxn);

	return 0;
}