#include<bits/stdc++.h>

using namespace std;

class Segment_Tree {
    private:
        int n;
        vector<int> arr;
        vector<int> segment_tree;
        map<int,pair<int,int>> freqs;

        int left(int i){
            return i<<1;
        }
        int right(int i){
            return (i<<1)+1;
        }

        int build(int L,int R,int idx){
            if(L==R){
                return segment_tree[idx]=arr[L];
            }

            int left_val = build()
        }
}

int main(){

    int n;
    int q;

    vector<int> arr(n+10);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    return 0;
}