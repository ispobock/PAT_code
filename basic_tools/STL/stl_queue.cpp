#include <cstdio>
#include <queue>
using namespace std;

int main(){
    queue<int> q;

    for(int i = 1; i <= 5; i++){
        q.push(i);
    }

    q.pop();

    // queue仅能通过front()和back()来访问元素
    printf("%d %d\n", q.front(), q.back());
    printf("%d\n", q.size());
    if(q.empty() == false){
        printf("not empty");
    }


    return 0;
}