#include <cstdio>
#include <queue>
using namespace std;

int M, N, L, T;

struct Node{
    int x, y, z;
}node;

bool inq[65][1300][135] = {false}; // 第几块，第几行，第几列
int slice[65][1300][135];
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z){
    if(x < 0 || y < 0 || z < 0 || x >= L || y >= M || z >= N){
        return false;
    }
    if(inq[x][y][z] == true || slice[x][y][z] == 0){
        return false;
    }
    return true;
}

int count;
void BFS(int x, int y, int z){
    queue<Node> q;
    node.x = x;
    node.y = y;
    node.z = z;
    q.push(node);
    count++;
    inq[x][y][z] = true;
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int new_x = top.x + X[i];
            int new_y = top.y + Y[i];
            int new_z = top.z + Z[i];
            if(judge(new_x, new_y, new_z)){
                node.x = new_x;
                node.y = new_y;
                node.z = new_z;
                q.push(node);
                count++;
                inq[new_x][new_y][new_z] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for(int i = 0; i < L; i++){  // 先枚举切片层号
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                scanf("%d", &slice[i][j][k]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < L; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(inq[i][j][k] == false && slice[i][j][k] == 1){
                    count = 0;
                    BFS(i, j, k);
                    if(count >= T){
                        ans += count;
                    }
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}