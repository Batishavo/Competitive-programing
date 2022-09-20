// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        list<pair<int,int>> balls;


        for(int i=0;i<N;i++){
            balls.push_back({color[i],radius[i]});
        }
        list<pair<int,int>>::iterator it=balls.begin();
        list<pair<int,int>>::iterator it2=balls.begin();
        while(it!= balls.end()){
            if(*it == *next(it)){

                balls.erase(next(it));
                balls.erase(it);

                --it;
                //cout<<*it.first<<" "<<*it.second<<endl;

            }
            else{
                ++it;
            }

            /*if(*it == NULL){
                return 0;
            }*/

        }


        return balls.size();
    }
};


// { Driver Code Starts.
int main() {

    int tt;
    //cin >> tt;
    Solution sol;
    tt=1;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}
  // } Driver Code Ends
