#include <stdio.h>
#include <algorithm>
using namespace std;

int main_sort(){
	int a[6] = {9, 4, 5, 6, 2, 7};
	sort(a, a+6);
	for(int i = 0; i < 6; i++){
		printf("%d", a[i]);
	}
	return 0;
}