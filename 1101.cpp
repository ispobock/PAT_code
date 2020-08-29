#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int a[100010];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max[100010] = {0};
    for(int i = 0; i < n; i++){
        if(i > 0){
            max[i] = max[i - 1];
        }
        if(a[i] > max[i]){
            max[i] = a[i];
        }
    }

    int count = 0, can[100010], min = 0x7fffffff;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] >= max[i] && a[i] <= min){
            can[count++] = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }

    printf("%d\n", count);
    for(int i = count - 1; i >= 0; i--){
        printf("%d", can[i]);
        if(i > 0){
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}