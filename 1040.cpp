#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[41];

int main(){
	int d, n;
	scanf("%d %d", &d, &n);
	v[0].push_back (d);
	for(int i = 1; i < n; i++){
		int count = 1;
		if(v[i - 1].size() == 1){
			v[i].push_back(v[i - 1][0]);
			v[i].push_back(1);
		}
		for(int j = 1; j < v[i - 1].size(); j++){
			if(v[i - 1][j - 1] == v[i - 1][j]){
				count++;
				if(j == v[i - 1].size() - 1){
					v[i].push_back(v[i - 1][j]);
					v[i].push_back(count);
				}
			}
			else{
				v[i].push_back(v[i - 1][j - 1]);
				v[i].push_back(count);
				count = 1;
				if(j == v[i - 1].size() - 1){
					v[i].push_back(v[i - 1][j]);
					v[i].push_back(count);
				}
			}
		}
	}
	for(int i = 0; i < v[n - 1].size(); i++){
		printf("%d", v[n - 1][i]);
	}
	return 0;
}