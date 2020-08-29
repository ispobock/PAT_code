#include <cstdio>
#include <vector>
using namespace std;

int N, K, P, T;

vector<int> temp, ans, fac;

// 比pow靠谱
int power(int x, int p){
    int ans = 1;
    for(int i = 0; i < p; i++){
        ans *= x;
    }
    return ans;
}

int max_sum = -1;
void DFS(int index, int sum_k, int sum, int num){
    if(temp.size() == 5){
        if(temp[0] == 5 && temp[1] == 6 && temp[2] == 6 && temp[3] == 6){
            int a = 1;
        }
    }

    if(sum_k == K && num == N){
        if(sum > max_sum){
            ans = temp;
            max_sum = sum;
        }
        return;
    }
    if(sum_k > K || num > N){
        return;
    }

    
    if(index - 1 >= 0){
        // choose
        temp.push_back(index);
        DFS(index, sum_k + 1, sum + index, num + fac[index]);
        temp.pop_back();
        // don't choose
        DFS(index - 1, sum_k, sum, num);
    }

    
}

int main(){
    scanf("%d %d %d", &N, &K, &P);
    int x = 0;
    while(T = power(x++, P), T <= N){ // 要加等号
        fac.push_back(T);              //此处一次性把所有的P次方计算完，节省计算量
    }
    DFS(fac.size() - 1, 0, 0, 0);
    if(ans.size() < K){
        printf("Impossible");
    }
    else{
        printf("%d = ", N);
        for(int i = 0; i < K; i++){
            printf("%d^%d", ans[i], P);
            if(i != K - 1){
                printf(" + ");
            }
        }
    }


    return 0;
}