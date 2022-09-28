#include<bits/stdc++.h>

using namespace std;
string cad;
int t;
int main(){
    cin>>t; 
    while (t--)
    {
        cin>>cad;
        
        vector<bool> sum(cad.size()+5,false);  

        char min = *min_element(cad.begin(), cad.end()),
             max = *max_element(cad.begin(), cad.end());
        for(int i=min;i<=max;i++){
            bool flag= false;
            for(int j=cad.size()-1;j>=0;j--){

                if(!flag && cad[j] == i){
                    flag=true;
                }
                else if(flag && cad[j]> i){
                    sum[j]=true;
                }
            }
        }

        for(int i=0;i<cad.size();i++){
            if(sum[i] && cad[i] <'9'){
                cad[i]++;
            }
        }
        sort(cad.begin(),cad.end());
        cout<<cad<<endl;
    }
    

    return 0;
}