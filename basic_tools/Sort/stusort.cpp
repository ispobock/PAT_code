#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Student{
	char name[10];
	char id[10];
	int score;
	int rank;
}stu[100010];

//自定义排序函数cmp
bool cmp(Student a, Student b){
	if(a.score != b.score){
		return a.score > b.score;
	}
	else{
		return strcmp(a.name, b.name) < 0;
	}
}

int main(){
	//排名的实现
	stu[0].rank = 1;
	for(int i = 1; i<n; i++){
		if(stu[i].score == stu[i - 1].score){
			stu[i].rank = stu[i - 1].rank;
		}else{
			stu[i].rank = i + 1;
		}
	}
	return 0;
}