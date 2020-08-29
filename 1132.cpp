#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool test(string z){
	long long n = 0;
	for(int i = 0; i < z.size(); i++){
		n = n * 10 + (z[i] - '0');
	}
	
	int size = z.size() / 2;

	string x, y;
	long long a = 0, b = 0;
	x += z.substr(0, size);
	y += z.substr(size, z.size() - size);
	for(int j = 0; j < x.size(); j++){
		a = a * 10 + (x[j] - '0');
	}
	for(int j = 0; j < y.size(); j++){
		b = b * 10 + (y[j] - '0');
	}
	if(a * b != 0){
		if(n % (a * b) == 0){
			return true;
		}
	}
	return false;
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string z;
		cin>>z;
		if(test(z)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}