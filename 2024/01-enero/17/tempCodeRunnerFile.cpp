#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
        
    int answer;
    int leftNumber;
    int n;
    int rightNumber;
    int test;
    int typeCase;
    int x;

    stack<int> notEqualNumbers;

    cin>>test;

    while(test--){

        //Reset values
        leftNumber = INT_MAX;
        rightNumber = INT_MIN;

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>typeCase>>x;
            switch (typeCase)
            {
            case 1:
                leftNumber=min(leftNumber,x);
                break;
            
            case 2:
                rightNumber=max(rightNumber,x);
                break;

            default:
                notEqualNumbers.push(x);
                break;
            }
        }

        answer=rightNumber-leftNumber+1;

        while(!notEqualNumbers.empty()){
            if(notEqualNumbers.top()>=leftNumber and 
                notEqualNumbers.top()<=leftNumber){
                    answer--;
                }           
        }

        cout<<max(answer,0)<<endl;

    }

    return 0;
}