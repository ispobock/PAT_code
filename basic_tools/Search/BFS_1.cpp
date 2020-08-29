#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
int m, n, matrix[maxn][maxn];
int X[5] = {0, 0, 1, -1};
int Y[5] = {1, -1, 0, 0};
bool inq[maxn][maxn] = {false};

struct Node{
    int x, y;
}node;

bool judge(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n){
        return false;
    }
    if(inq[x][y] == true || matrix[x][y] == 0){
        return false;
    }
    return true;
}

void BFS(int x, int y){
    queue<Node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    inq[x][y] = true;
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){ // 遍历此点上下左右
            int new_x = top.x + X[i]; // 注意这里是top.x
            int new_y = top.y + Y[i];
            if(judge(new_x, new_y)){
                node.x = new_x;
                node.y = new_y;
                q.push(node);
                inq[new_x][new_y] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(inq[i][j] == false && matrix[i][j] == 1){
                ans++;
                BFS(i, j); // 将此点所在块全部标注
            }
        }
    }

    printf("%d", ans);

    return 0;
}

/*
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
*/