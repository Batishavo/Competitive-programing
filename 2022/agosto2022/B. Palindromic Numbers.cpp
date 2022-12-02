#include<bits/stdc++.h>

using namespace std;

const int cero='0';

int t,
    n,
    tmp,
    num1,
    num2;

string cad,
       solution;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        cin>>cad;

        if(cad[0]<'9'){

            for(int i=0;i<n;i++){

                printf("%d",9-(cad[i]-'0'));

            }
            printf("\n");

        }
        else{

            for(int i=n-1;i>=0;i--){

                num1=1;
                num2=cad[i]-cero;

                if(num1-tmp>=num2){

                    char aux=num1-tmp-num2;
                    tmp=0;
                    aux+=cero;
                    solution+=aux;

                }
                else{

                    num1+=10;
                    char aux=num1-tmp-num2;
                    tmp=1;
                    aux+=cero;
                    solution+=aux;
                }

            }
            reverse(solution.begin(),solution.end());
            cout<<solution<<endl;
            solution="";
            tmp=0;

        }

    }

    return 0;
}
