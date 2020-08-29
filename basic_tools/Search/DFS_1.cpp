#include <cstdio>

const int maxn = 30;
int w[maxn], c[maxn]; // w,weight, c,value
int n, V, max_c = -1;

void DFS(int index, int now_w, int now_c){
    // recursion boundry
    if(index == n){
        return;
    }
    // don't choose
    DFS(index + 1, now_w, now_c);

    // choose
    if(now_w + w[index] <= V){
        if(now_c + c[index] > max_c){
            max_c = now_c + c[index];
        }
        DFS(index + 1, now_w + w[index], now_c + c[index]);
    }
}

int main(){
    scanf("%d %d", &n, &V);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d", max_c);

    return 0;
}