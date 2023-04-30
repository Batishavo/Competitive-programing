#include<bits/stdc++.h>

using namespace std;

string cad;

string inverting_string(){
    int left = 0,
        right = cad.length()-1;
    
    while(left < right){
        swap(cad[left],cad[right]);
        left++;
        right--;
    }

    return cad;
}

int main(){

    cin>>cad;
    
    cout<<inverting_string()<<endl;

    return 0;
}