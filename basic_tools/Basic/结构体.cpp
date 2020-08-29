#include <stdio.h>

struct Point{
	int x, y;
	Point(){} //默认构造函数，用以不初始化就能定义变量
	Point(int _x, int _y):x(_x), y(_y){} //用以x,y的初始化 
}pt[10];//定义结构体数组 

int main(){
	int num = 0;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <=3; j++){
			pt[num++] = Point(i,j);
		}
	}
	
	for(int i = 0; i < num; i++){
		printf("pt[%d].x = %d, pt[%d].y = %d\n", i, pt[i].x, i, pt[i].y);
	}
	
	return 0;
} 
