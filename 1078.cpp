#include <cstdio>
#include <cmath>

bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(1.0 * n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    bool hashtable[10010] = {false};
    int m, n, temp, h;
    scanf("%d %d", &m, &n);
    while(!is_prime(m)){
        m += 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        h = temp % m;
        if(hashtable[h] == false){
            hashtable[h] = true;
            printf("%d", h);
        }
        else{
            for(int step = 1; step < m; step++){  // 二次方探查法（正向）
                h = (temp + step * step) % m;
                if(hashtable[h] == false){
                    hashtable[h] = true;
                    printf("%d", h);
                    break;
                }
                if(step == m - 1){
                    printf("-");
                }
            }
        }
        if(i != n - 1){
            printf(" ");
        }
    }
    return 0;
}