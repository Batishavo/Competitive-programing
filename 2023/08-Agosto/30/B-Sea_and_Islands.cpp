#include<bits/stdc++.h>

using namespace std;

int main(){
    
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int k;
    
    char mat[110][110];

    char character = 'S';

    cin>>n>>k;

    for(int i = 0; i < n; i++){

        if(n%2==0){
            if(character == 'S'){
                character ='L';
            }
            else{
                character = 'S';
            }
        }

        for(int j = 0; j < n; j++){

            if(character == 'S' && k>0){
                character = 'L';
                k--;
            }
            else{
                character = 'S';
            }

            mat[i][j] = character;
        }
    }

    if(k==0){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            for (int  j = 0; j < n; j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
            
        }
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}