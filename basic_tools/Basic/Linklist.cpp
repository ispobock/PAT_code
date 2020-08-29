#include <cstdio>
#include <cstdlib>

struct node{
    int data;
    node* next;
};

node* create(){
    node *p, *pre;
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    pre = head;
    int temp;
    while(scanf("%d", &temp), temp != 0){
        p = new node;
        p->data = temp;
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int search(node* head, int x){
    int count = 0;
    node* p = head->next;
    while(p != NULL){
        if(p->data == x){
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert(node* head, int pos, int x){
    node* p = head;
    for(int i = 0; i < pos - 1; i++){
        p = p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void del(node* head, int x){
    node *p, *pre;
    p = head->next;
    pre = head;
    while(p != NULL){
        if(p->data == x){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = p;
            p = p->next;
        }
    }
}

int main(){
    node *head, *L;
    // 创建链表
    head = create();
    L = head->next;
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");

    // 在pos处插入元素x，并查询该元素个数
    int pos, x;
    scanf("%d %d", &pos, &x);
    insert(head, pos, x);
    int n = search(head, x);
    L = head->next;
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
    printf("%d\n", n);

    // 删除所有值为d的元素
    int d;
    scanf("%d", &d);
    del(head, d);
    L = head->next;
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }


    return 0;
}