#include <cstdio>
#include <set>
using namespace std;

const int maxn = 105;
int father[maxn];
int n, m;

int find_father(int x){
    if(x == father[x]){
        return x;
    }
    else{
        return find_father(father[x]);
    }
}

void Union(int a, int b){
    int faA = find_father(a);
    int faB = find_father(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        father[i] = i;
    }
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    set<int> st;
    for(int i = 1; i <= n; i++){
        st.insert(find_father(i));
    }
    printf("%d", st.size());

    return 0;
}