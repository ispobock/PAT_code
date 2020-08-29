#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int partition(int A[], int left, int right){
	
	//生成随机数
	int p = (int)(1.0*rand()/RAND_MAX*(right - left) + left + 0.5);
	swap(A[p], A[left]);

	int temp = A[left];
	while(left < right){
		while(left < right && A[right] > temp){
			right--;
		}
		A[left] = A[right];
		while(left < right && A[left] <= temp){ //注意这里的<=，不然遇到相等的数不能收敛
			left++;
		}
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quick_sort(int A[], int left, int right){
	if(left < right){
		int pos = partition(A, left, right);
		quick_sort(A, left, pos - 1);
		quick_sort(A, pos + 1, right);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int A[10], n = 5;
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	quick_sort(A, 0, 4);

	for(int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
}