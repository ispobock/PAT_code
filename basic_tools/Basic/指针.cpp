#include <stdio.h>

void wrap(int* &p1 , int* &p2){
	int* temp = p2;
	p2 = p1;
	p1 = temp;
}

void wrap2(int &a, int &b){
	int temp;
	temp = b;
	b = a;
	a = temp;
}

void wrap3(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
} 

int main_point(){
	int a;
	int* b;
	a = 233;
	b = &a;
	printf("%d\n", *b);
	*b = 3;
	printf("%d\n", a);
	
	//第一种交换方式 ：指针加引用,没改变原来的x和y 
	int x = 1, y = 2;
	int *p1 = &x, *p2 = &y;
	wrap(p1,p2);
	printf("%d %d\n", *p1, *p2);
	
	//第二种交换方式 ：纯引用 
	int u = 1, v = 2;
	wrap2(u, v);
	printf("%d %d\n", u, v);
	 
	//第三种交换方式 ：指针 
	int m = 1, n = 2;
	int *p3 = &m, *p4 =&n;
	wrap3(p3, p4);
	printf("%d %d\n", m, n);
	
	int x1 = 20, x2 =30;
	int *p5 = &x1 ;
	p5 = &x2; //第一种交换的本质 
	//*p5 = x2;//第三种交换的本质 
	printf("%d", *p5); 
	
	
	return 0;
}
