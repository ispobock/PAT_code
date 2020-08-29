#include <cstdio>
#include <set>
using namespace std;

int main(){
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(7);
    st.insert(89);

    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        printf("%d ", *it);
    }

    printf("\n");

    st.erase(st.find(7));
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        printf("%d ", *it);
    }

    printf("\n");

    st.clear();
    printf("%d", st.size());

    return 0;
}