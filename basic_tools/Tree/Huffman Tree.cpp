#include <cstdio>
#include <queue>
using namespace std;

//Huffman Tree即最小带权路径长度树
//优先队列，即Heap，其中参数greater<int>表示把数值最小的数放在队首
priority_queue<int , vector<int>, greater<int> > q;

int main(){
    int n;
    scanf("%d", &n);
    int temp, x, y, ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        q.push(temp);
    }
    while(q.size() > 1){
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }
    printf("%d", ans);
    return 0;
}