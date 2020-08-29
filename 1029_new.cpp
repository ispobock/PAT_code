#include <cstdio>
#include <cstdlib>

const int INF = 0x7fffffff;

typedef struct Linklist{
    int val;
    Linklist* next;
}node, *pnode;

int main(){
    int m, n, temp; 
    pnode L1 = (pnode)malloc(sizeof(node));
    pnode L2 = (pnode)malloc(sizeof(node));
    pnode p =L1;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        pnode q = (pnode)malloc(sizeof(node));
        scanf("%d", &temp);
        q->val = temp;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    pnode q = (pnode)malloc(sizeof(node));
    q->val = INF;
    p->next = q;
    q->next = NULL;

    scanf("%d", &n);
    p = L2;
    for(int i = 0; i < n; i++){
        pnode q = (pnode)malloc(sizeof(node));
        scanf("%d", &temp);
        q->val = temp;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    q = (pnode)malloc(sizeof(node));
    q->val = INF;
    p->next = q;
    q->next = NULL;

    int med = (m + n - 1) / 2;
    int count = 0;
    pnode i = L1->next, j = L2->next;
    while(count < med){
        if(i->val < j->val){
            count++;
            i = i->next;
        }
        else{
            count++;
            j = j->next;
        }
    }

    if(i->val < j->val){
        printf("%d", i->val);
    }
    else{
        printf("%d", j->val);
    }

    return 0;
}