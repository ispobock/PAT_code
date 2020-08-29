#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct fruit{
    string name;
    int price;
}f1, f2, f3;

struct cmp{
    // 传引用更快, 但要记得加const
    bool operator () (const fruit &f1, const fruit &f2){
        // 默认<是数字大的优先级大，此时重载，将数字小的优先级大
        return f1.price > f2.price;        
    }
};

int main(){
    // 自定义优先级
    priority_queue<fruit, vector<fruit>, cmp> q;

    f1.name = "apple";
    f1.price = 3;
    f2.name = "banana";
    f2.price = 1;
    f3.name = "peach";
    f3.price = 5;
    q.push(f1);
    q.push(f2);
    q.push(f3);

    // 仅有top()一种方式访问元素，即队首元素
    printf("%s %d", q.top().name.c_str(), q.top().price);

    return 0;
}