#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main(){
	vector<int> v;
	map<int, bool> mp;
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
		mp[temp] = true;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int an;
		for(int j = 0; j < v.size(); j++){
			an = v[j];
			if((an >= a && an <= b) || (an >= b && an <= a)) break;
		}
		if (mp[a] == false && mp[b] == false)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (mp[a] == false || mp[b] == false)
            printf("ERROR: %d is not found.\n", mp[a] == false ? a : b);
        else if (an == a || an == b)
            printf("%d is an ancestor of %d.\n", an, an == a ? b : a);
        else
            printf("LCA of %d and %d is %d.\n", a, b, an);
	}

	return 0;
}