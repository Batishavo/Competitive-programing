#include<bits/stdc++.h>

using namespace std;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
        
    int answer;
    int leftNumber;
    int n;
    int rightNumber;
    int test;
    int typeCase;
    int x;

    stack<int> notEqualNumbers;

    cin>>test;

    //cout<<"X";

    while(test--){

        //Reset values
        leftNumber = INT_MIN;
        rightNumber = INT_MAX;

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>typeCase>>x;
            switch (typeCase)
            {
            case 1:
                leftNumber=max(leftNumber,x);
                break;
            
            case 2:
                rightNumber=min(rightNumber,x);
                break;

            default:
                notEqualNumbers.push(x);
                break;
            }
        }

        if(rightNumber>=leftNumber){
            answer=rightNumber-leftNumber+1;
        }
        else{
            answer = 0;
        }

        while(!notEqualNumbers.empty()){
            if(notEqualNumbers.top()>=leftNumber and 
                notEqualNumbers.top()<=rightNumber)
            {
                answer--;
            }  
            notEqualNumbers.pop();         
        }

        cout<<max(answer,0)<<endl;

    }

    return 0;
}