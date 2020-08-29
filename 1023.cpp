#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign{
    int d[25];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign to_bign(char n[]){
    bign a;
    a.len = strlen(n);
    for(int i = 0; i < a.len; i++){
        a.d[i] = n[a.len - 1 -i] - '0';
    }
    return a;
}

bign multi(bign a, int b){
    bign c;
    int carry = 0, temp;
    for(int i = 0; i < a.len; i++){
        temp = a.d[i] * b + carry;
        c.d[i] = temp % 10;
        carry = temp / 10;
        c.len++;
    }
    if(carry > 0){
        while(carry != 0){
            c.d[c.len++] = carry % 10;
            carry /= 10;
        }
    }
    return c;
}

int main(){
    char n[25];
    scanf("%s", &n);
    bign c = to_bign(n);
    bign d = multi(c, 2);
    bign e = d;
    sort(c.d, c.d + c.len);
    sort(d.d, d.d + d.len);
    bool flag = false;
    for(int i = 0; i < c.len || i < d.len; i++){
        if(c.d[i] != d.d[i]){
            flag = true;
        }
    }

    if(flag){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }

    for(int i = e.len - 1; i >= 0; i--){
        printf("%d", e.d[i]);
    }


    return 0;
}