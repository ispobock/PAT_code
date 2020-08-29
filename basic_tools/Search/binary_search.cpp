#include <cstdio>

int low_bound(int a[], int left, int right, int x){
	while(left < right){
		int mid = (right + left) / 2;
		if(a[mid] >= x){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}

	return left;
}

int main(){
	int a[10000];
	int n = 5;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	printf("%d", upper_bound(a, 0, 4, 2));

}