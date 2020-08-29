#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<int> vi;
    for(int i = 0; i < 5; i++){
        vi.push_back(i);
    }
    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
        printf("%d", *it);
    }

    printf("\n");
    
    vi.pop_back();
    for(int i = 0; i < vi.size(); i++){
        printf("%d", vi[i]);
    }

    printf("\n");

    vi.insert(vi.begin() + 2, 5);
    vi.erase(vi.begin() + 3);
    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
        printf("%d", *it);
    }

    return 0;
}