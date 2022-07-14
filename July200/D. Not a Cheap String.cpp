#include<bits/stdc++.h>

using namespace std;

int arr[300];

int main(){

    int test;
    scanf("%d",&test);

    while(test--){
        for(int i='a';i<='z';i++){
            arr[i]=0;
        }
        string cad;
        int n;
        int total=0;
        cin>>cad>>n;

        for(int i=0;i<cad.length();i++){

            arr[cad[i]]++;
            total+=cad[i]-'a'+1;
        }
        for(int i='z';i>='a';i--){
            int num= (i-'a'+1)*arr[i];
            if(total-num<=n){

                int usable= n-(total-num);

                int no_rest=usable/(i-'a'+1);

                arr[i]= no_rest;

                break;
            }
            total-=num;
            arr[i]=0;
        }
        cout<<"--";
        for(int i=0;i<cad.length();i++){

            if(arr[cad[i]]>0){
                arr[cad[i]]--;
                cout<<cad[i];
            }

        }
        cout<<endl;
    }

    return 0;
}
