#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int m, n, k;
    int sq[1010];
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++){
        stack<int> s;
        int max = n + 1;
        for(int j = 0; j < n; j++){
            scanf("%d", &sq[j]);
        }
        bool flag = true;
        for(int j = n - 1; j >= 0; j--){
            if(!s.empty()){
                if(sq[j] > s.top()){
                    if(s.size() < m){
                        s.push(sq[j]);
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else if(s.top() < max){
                    max = s.top();
                    s.pop();
                    while(!s.empty() && s.top() > sq[j]){
                        if(s.top() > max){
                            flag = false;
                            break;
                        }
                        max = s.top();
                        s.pop();
                    }
                    s.push(sq[j]);
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                s.push(sq[j]);
            }
        }
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}