#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;

void merge(int A[], int L1, int R1, int L2, int R2){
	int i = L1, j = L2;
	int C[maxn], index = 0;
	while(i <= R1 && j <= R2){
		if(A[i] < A[j]){
			C[index++] = A[i++];
		}
		else{
			C[index++] = A[j++];
		}
	}
	while(i <= R1){
		C[index++] = A[i++];
	}
	while(j <= R2){
		C[index++] = A[j++];
	}

	for(int i = 0; i < index; i++){
		A[L1 + i] = C[i];
	}
}

//recursion
void merge_sort(int A[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid+1, right);
		merge(A, left, mid, mid+1, right);
	}
}

//iteration
void merge_sort_iter(int A[], int n){
	for(int step = 2; step / 2 < n; step *= 2){
		for(int i = 1; i <= n; i += step){
			int mid = i + step / 2 - 1;
			if(mid + 1 <= n){
				merge(A, i, mid, mid + 1, min(i + step - 1, n));
			}
		}
	}
}

int main(){
	int A[maxn];
	for(int i = 0; i < 10; i++){
		scanf("%d", &A[i]);
	}
	merge_sort(A, 0, 9);
	for(int i = 0; i < 10; i++){
		printf("%d ", A[i]);
	}
	return 0;
}