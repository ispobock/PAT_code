#include <stdio.h>

const int maxn = 10;

int main(){
	int A[maxn], n;
	//��������
	void insertSort(){
		for(int i = 2; i <= n; i++){
			//����n-1������
			int temp = A[i], j = i;
			while(j > 1 && temp < A[j - 1]){
				//ֻҪtempС��A[j-1]����A[j-1]����һλ
				A[j] = A[j - 1];
				j--;
			}
			A[j] = temp;
		}
	}
	return 0;
}