#include <stdio.h>

struct Point{
	int x, y;
	Point(){} //Ĭ�Ϲ��캯�������Բ���ʼ�����ܶ������
	Point(int _x, int _y):x(_x), y(_y){} //����x,y�ĳ�ʼ�� 
}pt[10];//����ṹ������ 

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
