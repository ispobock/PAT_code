#include <cstdio>

struct Node{
    char letter;
    int next;
}node[1000000];

int main(){
    int ad1, ad2, n;
    scanf("%d %d %d", &ad1, &ad2, &n);
    int now, next;
    char temp;
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &now, &temp, &next);
        node[now].letter = temp;
        node[now].next = next;
    }

    bool hash_table[1000000] = {false};
    int p = ad1;
    while(p != -1){
        hash_table[p] = true;
        p = node[p].next;
    }

    p = ad2;
    while(hash_table[p] != true && p != -1){
        p = node[p].next;
    }

    if(p == -1){
        printf("-1");
    }
    else{
        printf("%05d", p);
    }
    
    return 0;
}