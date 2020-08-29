#include <cstdio>
#include <cmath>

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(1.0 * n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int reverse(int n, int d){
    int ans = 0;
    while(n != 0){
        ans = ans * d + n % d;
        n /= d;
    }
    return ans;
}

int main(){
    int n, d;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        scanf("%d", &d);
        int r = reverse(n, d);
        if(isPrime(n) && isPrime(r)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}