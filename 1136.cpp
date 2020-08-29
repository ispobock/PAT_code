#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
bool ispar(string a){
	string b = a;
	reverse(b.begin(), b.end());
	if(a == b){
		return true;
	}
	return false;
}

string add(string a, string b){
	int len1 = a.length();
	int len2 = b.length();
	int d1[1010] = {0};
	int d2[1010] = {0};
	int d3[1010] = {0};
	int len3 = max(len1, len2);
	for(int i = 0; i < len1; i++){
		d1[i] = a[len1 - 1 - i] - '0';
	}
	for(int i = 0; i < len2; i++){
		d2[i] = b[len2 - 1 - i] - '0';
	}
	int carry = 0;
	for(int i = 0; i < len3; i++){
		int temp;
		temp = d1[i] + d2[i] + carry;
		d3[i] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		d3[len3++] = carry;
	}
	string c;
	for(int i = len3 - 1; i >= 0; i--){
		c = c + (char)(d3[i] + '0');
	}
	return c;
}


int main(){
	string n;
	cin>>n;

	int count = 0;
	while(!ispar(n)){
		string r = n;
		reverse(r.begin(), r.end());
		string sum = add(n, r);
		printf("%s + %s = %s\n", n.c_str(), r.c_str(), sum.c_str());
		n = sum;
		count++;
		if(count == 10){
			break;
		}
	}
	if(ispar(n)){
		printf("%s is a palindromic number.\n", n.c_str());
	}
	else{
		printf("Not found in 10 iterations.\n");
	}

	return 0;
}