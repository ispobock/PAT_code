#include <cstdio>
#include <algorithm>
using namespace std;

int insert_sort(int A[], int n, int B[]){
	int count = 0;
	for(int i = 0; i < n; i++){
		int temp = A[i];
		int j = 0;
		while(A[j] < A[i] && j < i){
			j++;
		}
		for(int k = i; k > j; k--){
			A[k] = A[k-1];
		}
		A[j] = temp;
		if(count == n){
			return 1;
		}
		count = 0;
		for(int l = 0; l < n; l++){
			if(A[l] == B[l]){
				count++;
			}
		}
	}
	return -1;
}

void merge(int A[], int L1, int R1, int L2, int R2){
	int B[100];
	int i = L1, j = L2, index = 0;
	while(i <= R1 && j <= R2){
		if(A[i] <= A[j]){
			B[index++] = A[i++];
		}
		else{
			B[index++] = A[j++];
		}
	}
	while(i <= R1){
		B[index++] = A[i++];
	}
	while(j < R2){
		B[index++] = A[j++];
	}
	for(int i = 0; i < index; i++){
		A[L1+i] = B[i];
	}
}


int merge_sort(int A[], int B[], int n){
	int count = 0;
	for(int step = 2; step/2 <= n; step *= 2){
		for(int i = 0; i < n; i += step){
			int mid = i + step /2 - 1;
			if(mid + 1 < n){
				merge(A, i, mid, mid + 1, min(i + step - 1, n - 1));
			}
		}
		if(count == n){
			return 1;
		}
		count = 0;
		for(int l = 0; l < n; l++){
			if(A[l] == B[l]){
				count++;
			}
		}
	}
	return -1;
}

int main(){
	int n, A[110], A1[110], B[110];
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &A[i]);
		A1[i] = A[i];
	}
	for(int i = 0; i<n; i++){
		scanf("%d", &B[i]);
	}
	
	int is = insert_sort(A, n, B);
	if(is == 1){
		printf("Insertion Sort\n");
		for(int i = 0; i < n - 1; i++){
			printf("%d ", A[i]);
		}
		printf("%d\n", A[n-1]);
	}

	int ms = merge_sort(A1, B, n);
	if(ms == 1){
		printf("Merge Sort\n");
		for(int i = 0; i < n - 1; i++){
			printf("%d ", A1[i]);
		}
		printf("%d\n", A1[n-1]);
	}
	
	return 0;
}