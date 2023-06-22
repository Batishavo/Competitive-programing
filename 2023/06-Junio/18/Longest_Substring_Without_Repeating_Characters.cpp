#include <bits/stdc++.h>

using namespace std;

string s =
    //"jdkafnlcdsalkxcmpoiuytfccv"
    "abcabcbb"
    ;

bool memo['z' + 10];
int lef = 0,
    answer = 1;

int main()
{

    memo[s[0]] = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (memo[s[i]] != 0)
        {
            
            for(int j=lef;;j++){
                memo[s[j]]=0;
                if(s[j]==s[i]){
                    
                    lef = j+1;
                    break;
                }
            }
            
        }
        memo[s[i]]=1;
        answer = max(answer, i - lef +1 );    
        //cout<<i<<" "<<lef<<" "<<answer<<endl;
    }

    cout << answer;
    return 0;
}