#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL; //防溢出，用long long 
//LL inf = (1LL << 63) - 1;

LL to_real(string a, LL radix){
	LL re = 0;
	for(string::iterator it = a.begin(); it != a.end(); it++){
		if(*it >= '0' && *it <= '9'){
			re = re*radix + (*it - '0');
		}
		else{
			re = re*radix + (*it - 'a' + 10);
		}
	}

	return re;
}

LL max(LL a, LL b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}


int main(){
	string a, b;
	LL tag, radix;
	cin >> a;
	cin >> b;
	scanf("%lld %lld", &tag, &radix);

	LL real = 0;
	string an, num;
	if(tag == 1){
		real = to_real(a, radix);
		an = b;
	}
	else{
		real = to_real(b, radix);
		an = a;
	}
	
	LL left = -1;
	for(string::iterator it = an.begin(); it != an.end(); it++){
		if(*it >= '0' && *it <= '9'){
			if(*it - '0' > left){
				left = *it - '0';
			}
		}
		else{
			if(*it - 'a' + 10> left){
				left = *it - 'a' + 10;
			}
		}
	}
	
	left++;

	LL right = max(left, real) + 1; //进制数最大不会超过真值（超过两位数）和left中的最大值
	LL ans = -1;
	//二分
	while(left <= right){
		LL mid = (left + right) / 2;
		LL mid_val = to_real(an, mid);
		if(mid_val < 0 || mid_val > real){ //注意溢出
			right = mid - 1;
		}
		else if(mid_val == real){
			ans = mid;
			break;
		}
		else{
			left = mid + 1;
		}
	}

	if(ans != -1){
		printf("%lld\n", ans);
	}
	else{
		printf("Impossible\n");
	}
	
	return 0;
}