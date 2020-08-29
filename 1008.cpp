#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> num;

bool islegal(string s){
	double ans = 0.0;
	bool flag = false;
	int count = 0;
	if(s[0] <= '9' && s[0] >= '0'){
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it <= '9' && *it >= '0' && flag == false){
				ans = ans * 10 + *it - '0';
			}
			else if(*it <= '9' && *it >= '0' && flag == true && count < 2){
				if(count == 0){
					ans += (*it - '0') * 0.1;
				}
				else if(count == 1){
					ans += (*it - '0') * 0.01;
				}
				count++;
			}
			else if(*it == '.' && flag == false){
				flag = true;
			}
			else{
				return false;
			}
		}
	}
	else if(s[0] == '-'){
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it == '-' && it == s.begin()){
				continue;
			}
			if(*it <= '9' && *it >= '0' && flag == false){
				ans = ans * 10 + *it - '0';
			}
			else if(*it <= '9' && *it >= '0' && flag == true && count < 2){
				if(count == 0){
					ans += (*it - '0') * 0.1;
				}
				else if(count == 1){
					ans += (*it - '0') * 0.01;
				}
				count++;
			}
			else if(*it == '.' && flag == false){
				flag = true;
			}
			else{
				return false;
			}
		}
		ans = -1.0 * ans;
	}
	else{
		return false;
	}

	if(ans > 1000 || ans < -1000){
		return false;
	}

	num.push_back(ans);
	return true;
}

int main(){
	int n; 
	scanf("%d", &n);
	int notlegal = 0;
	for(int i = 0; i < n; i++){
		string str;
		cin>>str;
		if(!islegal(str)){
			notlegal++;
			printf("ERROR: %s is not a legal number\n", str.c_str());
		}
	}
	double res = 0.0;
	if(notlegal == n){
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(num.size() > 1){
		for(int i = 0; i < num.size(); i++){
			res += num[i];
		}
		printf("The average of %d numbers is %.2lf\n", num.size(), res / num.size());
	}
	else if(num.size() == 1){
		printf("The average of 1 number is %.2lf\n", num[0]);
	}
	return 0;
}