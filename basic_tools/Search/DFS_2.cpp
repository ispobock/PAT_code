#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100;
int N, K, X, max_squ = -1; // from N choose K, make K's sum = X
int A[maxn];
vector<int> temp, ans;

void DFS(int index, int now_K, int sum, int sum_squ){
    // recursion boundry
    if(now_K == K){
        if(sum == X && sum_squ > max_squ){
            max_squ = sum_squ;
            ans = temp; // record
        }
        return;
    }

    if(index == N || sum > X){
        return;
    }

    // choose
    temp.push_back(A[index]);
    DFS(index + 1, now_K + 1, sum + A[index], sum_squ + A[index] * A[index]);
    temp.pop_back();

    // don't choose
    DFS(index + 1, now_K, sum, sum_squ);
}


int main(){
    scanf("%d %d %d", &N, &K, &X);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    DFS(0, 0, 0, 0);
    for(int i = 0; i < K; i++){
        printf("%d ", ans[i]);
    }

    return 0;
}