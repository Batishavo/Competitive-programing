#include<bits/stdc++.h>

using namespace std;

int t,n,arr[200];

bool flag=true;

vector<int> anwer;


int main(){

    scanf( "%d",&t);
    
    while(t--){
        
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        anwer.push_back(arr[0]);
        for(int i=1;i<n;i++){

            int num1=anwer[i-1]-arr[i],
                num2=arr[i]+anwer[i-1];

            if((num1>=0 && num2>=0) && num1!=num2){
                flag=false;
                break;
            }
            else{
                int num=(num1>=0 )?num1:num2;
                anwer.push_back(num);
            }

        }
        if(flag){
            for(auto x: anwer){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        flag=true;
        anwer.clear();
        
    }

    return 0;
}