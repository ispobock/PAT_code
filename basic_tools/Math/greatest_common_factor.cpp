#include <cstdio>

/*
辗转相除法
gcd(a, b) = gcd(b, a % b)
gcd(a, 0) = a
*/

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));
    printf("lcm(%d, %d) = %d\n", m, n, m*n/gcd(m, n));
    return 0;
}