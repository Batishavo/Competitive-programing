#include <bits/stdc++.h>

using namespace std;

string lengthOfLongestSubstring =
    "jdkafnlcdsalkxcmpoiuytfccv"
    //abcabcbb"
    ;

int memo['z' + 10];
int lef = 0,
    answer = 1;

int main()
{

    memo[lengthOfLongestSubstring[0]] = 0;

    for (int i = 1; i < lengthOfLongestSubstring.length(); i++)
    {
        if (memo[lengthOfLongestSubstring[i]] != 0)
        {
            lef = memo[lengthOfLongestSubstring[i]]-1;
            
        }
        else
        {
            answer = max(answer, i - lef );
            //cout << i << " " << lef << endl;
        }
        memo[lengthOfLongestSubstring[i]] = i;
    }

    cout << answer;
    return 0;
}