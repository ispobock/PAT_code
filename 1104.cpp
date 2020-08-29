#include <cstdio>

int main(){
    int n;
    double seg[100010];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &seg[i]);
    }

    double ans = 0.0;

    for(int i = 1; i <= n; i++){
        ans += seg[i-1] * i * (n + 1 - i);
    }

    printf("%.2lf\n", ans);

    return 0;
}