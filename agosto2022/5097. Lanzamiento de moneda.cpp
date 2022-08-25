#include<stdio.h>
#include <vector>

using namespace std;
int n;

void dfs(vector<char> v){

    if(v.size()==n){
        for (int i = 0; i < v.size(); ++i) {
            printf("%c",v[i] );
        }
        printf("\n");
        return;
    }
    v.push_back('A');
    dfs( v );

    v.pop_back();
    v.push_back('X');

    dfs( v );

}

int main(){

    scanf("%d",&n);
    std::vector<char> cad;
    dfs(cad);

    return 0;
}
