#include<bits/stdc++.h>

using namespace std;
string cad,aux;
int t;
int main(){
    cin>>t; 
    while (t--)
    {
        vector<int> nums(15,0);  
        cin>>cad;
        aux=cad;
        sort(cad.begin(), cad.end());
        for(int i=0;i<cad.size();i++){
            nums[cad[i]-'0']++;
        }
        int p1=0,
            p2=0;
        
        while(p1<cad.size() && p2<cad.size()){
            
        }
        
    }
    

    return 0;
}