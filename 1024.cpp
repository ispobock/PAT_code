#include <cstdio>
#include <cstring>

struct bign{
    int d[1000];
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
        a.d[i] = n[a.len - 1 - i] - '0';
    }
    return a;
}

bign reverse(bign a){
    bign b;
    b.len = a.len;
    for(int i = 0; i < a.len; i++){
        b.d[i] = a.d[a.len - 1 - i];
    }
    return b;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0, temp;
    for(int i = 0; i < a.len || i < b.len; i++){
        temp = a.d[i] + b.d[i] + carry;
        c.d[i] = temp % 10;
        carry = temp / 10;
        c.len++;
    }
    if(carry > 0){
        c.d[c.len++] = carry;
    }
    return c;
}

bool is_pal(bign a){
    for(int i = 0; i <= a.len / 2; i++){
        if(a.d[i] != a.d[a.len - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    char n[1000];
    int k;
    scanf("%s %d", n, &k);
    bign a = to_bign(n);
    int i = 0;
    for(; i < k; i++){
        if(is_pal(a)){
            break;
        }
        a = add(a, reverse(a));
    }

    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.d[i]);
    }
    printf("\n%d", i);

    return 0;
}