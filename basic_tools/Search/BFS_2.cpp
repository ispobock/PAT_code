#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int m, n;
int sx, sy, tx, ty;
const int maxn = 100;
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};

int X[5] = {0, 0, 1, -1};
int Y[5] = {1, -1, 0, 0};

struct Node{
    int x, y, step;
}node;

bool judge(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n){
        return false;
    }
    if(inq[x][y] == true || maze[x][y] == '*'){
        return false;
    }
    return true;
}

int BFS(){
    queue<Node> q;
    node.x = sx, node.y = sy;
    node.step = 0;
    q.push(node);
    inq[sx][sy] = true;
    while(!q.empty()){
        Node top = q.front();
        q.pop(); //进队后即出
        if(top.x == tx && top.y == ty){
            return top.step;
        }
        for(int i = 0; i < 4; i++){
            int new_x = top.x + X[i];
            int new_y = top.y + Y[i];
            if(judge(new_x, new_y)){
                node.x = new_x, node.y = new_y;
                node.step = top.step + 1;
                q.push(node);
                inq[new_x][new_y] = true;
            }
        }
    }

    return -1;
}

int main(){

    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < m; i++){
        getchar();
        for(int j = 0; j < n; j++){
            scanf("%c", &maze[i][j]);
        }
        maze[i][n + 1] = '\0';
    }
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

    printf("%d", BFS());

    return 0;
}

/*

5 5
.....
.*.*.
.*.*.
.***.
....*
2 2 4 3

*/