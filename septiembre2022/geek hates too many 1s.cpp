// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {

    int count_bits(int n)
    {

      string binary = bitset< 64 >(n).to_string();

      return 64 - binary.find('1');
    }

    int clearbit(int num,int i){
        int mask= ~(1<<i);
        return num & mask;
    }
    string makeBinary(int query){
        return bitset<32>(query).to_string(); //to binary
    }
    int make0(int zero,int ini,int i,int query){

        int num=i+ini;

        for(int j=0;j<zero;j++){
            query=clearbit(query,num);
            num+=3;
        }
        return query;

    }

  public:
    int noConseBits(int query) {
        int num  = count_bits( query),
            cont = 0;

        string binary=makeBinary(query);
        //cout<<binary<<endl;
        reverse(binary.begin(),binary.end());

        for(int i=0;i<num;i++){

            if(binary[i]=='1'){
                cont++;
            }
            else{
                if(cont>=3){
                    int zero = cont/3,
                        ini  = cont%3;

                    query=make0(zero,ini,i-cont,query);

                }
                cont=0;
            }

        }
        if(cont>=3){
            int zero = cont/3,
                ini  = cont%3;

            query=make0(zero,ini,num-cont,query);

        }
        //cout<<makeBinary(query)<<endl;
        return query;

    }

};


// { Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int query;
        cin >> query;
        int ans = sol.noConseBits(query);
        cout << ans << '\n';
    }

    return 0;
}
  // } Driver Code Ends
