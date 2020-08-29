#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

struct Mice{
    int num;
    int weight;
    int rank;
}mice[maxn];

int main(){
    int np, ng;
    scanf("%d %d", &np, &ng);
    for(int i = 0; i < np; i++){
        scanf("%d", &mice[i].weight);
        mice[i].num = i;
    }

    queue<Mice> q[maxn];

    for(int i = 0; i < np; i++){
        int order;
        scanf("%d", &order);
        q[0].push(mice[order]);
    }

    //计算轮数
    int turns = 0;
    int p = np;
    while(p != 1){
        if(p % ng == 0){
            p = p / ng;
            turns++;
        }
        else{
            p = p / ng + 1;
            turns++;
        }
    }

    int r = np;
    for(int i = 0; i < turns; i++){

        int rank;
        if(r % ng == 0){
            rank = r / ng + 1;
            r = r / ng;
        }
        else{
            rank = r / ng + 2;
            r = r / ng + 1;
        }

        while(!q[i].empty()){
            int max = -1, max_num;
            Mice temp;
            for(int j = 0; j < ng && !q[i].empty(); j++){
                temp = q[i].front();
                q[i].pop();
                mice[temp.num].rank = rank;
                if(temp.weight > max){
                    max = temp.weight;
                    max_num = temp.num;
                }
            }
            q[i + 1].push(mice[max_num]);
        }
    }

    mice[q[turns].front().num].rank = 1;

    for(int i = 0; i < np; i++){
        printf("%d", mice[i].rank);
        if(i != np - 1){
            printf(" ");
        }
    }

    return 0;
}