#include <bits/stdc++.h>

using namespace std;

string cad,
    cad2,
    tmp;

int yay,
    who,
    arr[300];

int main()
{

    cin >> cad >> cad2;
    
    for(int i=0;i<cad2.size();i++){
        arr[cad2[i]]++;
    }
    for(int i=0;i<cad.size();i++){
        if(arr[cad[i]]>0){
            yay++;
            arr[cad[i]]--;
        }
        else{
            tmp+=cad[i];
        }
    }
    for(int i=0;i<tmp.size();i++){
        char cha=tmp[i];
        if(tmp[i]>='a' && tmp[i]<='z'){
            cha=toupper(cha);
        }
        else{
            cha=tolower(cha);
        }
        if(arr[cha]>0){
            who++;
            arr[cha]--;
        }
    }
    printf("%d %d\n",yay,who);

    return 0;
}