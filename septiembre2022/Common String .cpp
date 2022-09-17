// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{

int concatenation(int i,int tsize,string cad,string comp){

    int pivote=0;

    for(i;i<tsize;i++){

        if(pivote==comp.size()){
            return 0;
        }

        if(cad[i]!=comp[pivote++]){
            return -1;
        }

    }

    return 1;
}

string cads(string cad,string comp){
    int aux = -1,
        tmp = 0;

    for(int i=0;i<cad.size();i++){

        if(cad[i]==comp[0]){

            aux=concatenation(i,cad.size(),cad,comp);

            if(aux!=-1){
                tmp=i;
                break;
            }

        }

    }
    if(aux==-1)cad+=comp;
    else if(aux==1){
        for(int i=cad.size()-tmp;i<comp.size();i++){
            cad+=comp[i];
        }
    }

    return cad;
}

public:
    string commonString(string s,string t){
        // Code here
        string cad1=cads(s,t),
               cad2=cads(t,s);
        //cout<<cad1<<" "<<cad2<<endl;

        if(cad1.size()==cad2.size()){
            return (string(cad1)<string(cad2))?cad1:cad2;
        }
        return (cad1.size()<cad2.size())?cad1:cad2;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        Solution ob;
        cout<<ob.commonString(s,t)<<endl;
    }
    return 0;
}  // } Driver Code Ends
