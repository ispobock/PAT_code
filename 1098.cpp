#include <cstdio>
#include <algorithm>
using namespace std;

int origin[110], temp[110], changed[110];
int n;

void show(int A[]){
    for(int i = 1; i <= n; i++){
        printf("%d", A[i]);
        if(i < n){
            printf(" ");
        }
    }
}

bool isSame(int A[], int B[]){
    for(int i = 1; i <= n; i++){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}

bool insert_sort(){
    bool flag = false;
    for(int i = 2; i <= n; i++){
        if(i != 2 && isSame(origin, changed)){
            flag = true;
        }
        sort(origin, origin + i + 1);
        if(flag){
            return true;
        }
    }
    return false;
}

void downAdjust(int left, int right){
    int i = left, j = 2 * i;
    while(j <= right){
        if(j + 1 <= right && temp[j + 1] > temp[j]){
            j = j + 1;
        }
        if(temp[i] < temp[j]){
            swap(temp[i], temp[j]);
            i = j;
            j = 2 * i;
        }
        else{
            break;
        }
    }
}

void heap_sort(){
    bool flag = false;
    for(int i = n / 2; i >= 1; i--){  //建堆
        downAdjust(i, n);
    }
    for(int i = n; i > 1; i--){
        if(i != n && isSame(temp, changed)){
            flag = true;
        }
        swap(temp[1], temp[i]);
        downAdjust(1, i - 1);
        if(flag){
            show(temp);
            return;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &changed[i]);
    }
    if(insert_sort()){
        printf("Insertion Sort\n");
        show(origin);
    }
    else{
        printf("Heap Sort\n");
        heap_sort();
    }
    return 0;
}