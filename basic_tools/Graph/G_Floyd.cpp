//Floyd算法，解决全源最短路问题，思想异常简洁，但复杂度O(V^3)
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAXV = 200;
int n;
int dis[MAXV][MAXV];
//fill(dis[0], dis[0] + MAXV * MAXV, INF);
//令dis[i][i] = 0

void Floyd(){
    for(int k = 0; k < n; k++){ //枚举中介点k
        for(int i = 0; i < n; i++){ //枚举所有定点对(i, j)
            for(int j = 0; j < n; j++){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j]; //以k为中介点更优
                }
            }
        }
    }
}
//此法仅需注意遍历的次序，是先遍历中介点k