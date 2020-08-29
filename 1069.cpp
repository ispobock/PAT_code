#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

void to_array(int num, int a[]){
    for(int i = 0; i < 4; i++){
        a[i] = num % 10;
        num /= 10;
    }
}

int to_int(int a[]){
    int num = 0;
    for(int i = 0; i < 4; i++){
        num = num * 10 + a[i];
    }
    return num;
}

int main(){
    int num, a[5], max, min;
    scanf("%d", &num);

    while(1){
        to_array(num, a);
        sort(a, a + 4);
        min = to_int(a);
        sort(a, a + 4, cmp);
        max = to_int(a);
        num = max - min;
        printf("%04d - %04d = %04d\n", max, min, num);
        if(num == 6174 || num == 0){
            break;
        }
    }
    return 0;
}