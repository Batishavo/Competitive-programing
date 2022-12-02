#include<bits/stdc++.h>
using namespace std;

const int limit=10e5+10;

map<string,bool>sub_strings;
string arr[limit];

int main(){

    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            cin>>arr[i];
            sub_strings[arr[i]]=true;

        }
        //printf("--");
        for(int i=0;i<n;i++){

            bool flag=false;

            for(int j=1;j<arr[i].length();j++){
                string pref=arr[i].substr(0, j);
                string post=arr[i].substr(j, arr[i].length() - j);

                if(sub_strings[pref] && sub_strings[post]){
                    flag=true;
                    break;
                }

            }
            printf("%d",flag);

        }
        printf("\n");
        sub_strings.clear();

    }

    return 0;
}
