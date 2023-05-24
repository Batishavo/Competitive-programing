#include<bits/stdc++.h>

using namespace std;

string cad;

list<char> my_list;
list<char>::iterator it = my_list.begin();

int main(){

    cin>>cad;
    for(int i=0;i<cad.size();i++){
        my_list.push_back(cad[i]);
    }
    it = my_list.begin();
    while(it != my_list.end()){
        //cout<<*it<<" "<<*next(it)<<endl;
        if(*it == *next(it)){
            next(it)=my_list.erase(next(it));
            it=my_list.erase(it);
            if(prev(it)!=my_list.end()){
                --it;
            }
        }
        else{
            ++it;
        }
    }

    it = my_list.begin();
    while(it != my_list.end()){
        cout<<*it;
        it++;
    }
  
    cout<<endl;
    return 0;
}