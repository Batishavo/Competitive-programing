// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {

    vector<bool> isPrime;
    vector<int> primes;

    void criba(int n) {
        isPrime = vector<bool>(n, true);
        primes = vector<int>();
        isPrime[0] = isPrime[1] = false;
        for (int i=2; i<n;i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j=i+i; j<n; j+=i){
                    isPrime[j] = 0;
                }
            }
        }
    }


    int cal(int num){
        for(auto x:primes){
            if(x>= num){
                return -1;
            }
            if(num%x==0 && isPrime[num/x]==1 && x!=num/x){
                return x;
            }
        }
        return -1;
    }

    public:
      int minMoves(int query){
         criba(100000);
         int p1=query,
             p2=query,
             cont=0;
         while(true){

            int num1=cal(p1),
                num2=-1;
            if(p2>5){
                num2=cal(p2);
            }

            if(num1!=-1 || num2!=-1){
                return cont;
            }
            p1+=2;
            p2-=2;
            cont++;
         }

         return cont;
      }
};

// { Driver Code Starts.

int main()
{

    int tt;
    cin >> tt;
    Solution sol;
    //tt=1;
    while (tt--)
    {


          int query;
          cin >> query;
          int ans = sol.minMoves(query);
          cout << ans << "\n";

    }
    return 0;
}  // } Driver Code Ends
