#include <cstdio>
//同BFS_3

int m, n;
int matrix[100][100];
bool isv[100][100] = {false}; // is_visited

bool judge(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n ){
        return false;
    }
    if(matrix[x][y] == 0 || isv[x][y] == true){
        return false;
    }
    return true;
}

void DFS(int x, int y){
    if(!judge(x, y)){
        return;
    }
    else{
        isv[x][y] = true;
    }
    DFS(x + 1, y);
    DFS(x, y + 1);
    DFS(x - 1, y);
    DFS(x, y - 1);
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(isv[i][j] == false && matrix[i][j] == 1){
                count++;
                DFS(i, j);
            }
        }
    }
    printf("%d", count);

}
