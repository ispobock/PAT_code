#include <stdio.h>

const int maxn = 10;

int main(){
	int A[maxn], n;
	//插入排序
	void insertSort(){
		for(int i = 2; i <= n; i++){
			//进行n-1趟排序
			int temp = A[i], j = i;
			while(j > 1 && temp < A[j - 1]){
				//只要temp小于A[j-1]，将A[j-1]后移一位
				A[j] = A[j - 1];
				j--;
			}
			A[j] = temp;
		}
	}
	return 0;
}