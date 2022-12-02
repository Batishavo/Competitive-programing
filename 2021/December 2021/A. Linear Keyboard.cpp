#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int arr['z'+10];
    scanf("%d",&n);
    while(n--){
        string cad,word;
        cin>>cad;
        for(int i=0;i<cad.length();i++){
            arr[cad[i]]=i+1;
        }
        cin>>word;
        int cont=0;
        for(int i=1;i<word.length();i++){
            cont+=abs(arr[word[i]]-arr[word[i-1]]);
        }
        printf("%d\n",cont);
    }

    return 0;
}
