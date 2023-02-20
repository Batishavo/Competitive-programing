#include<bits/stdc++.h>

using namespace std;

string num1,
    num2;

string mult(){
    string answer;
    int acarreo=0,
        tmp;
    for(int i=0;i<num1.size()+num2.size();i++){
        answer+='0';
    }

    for(int i=num1.size()-1;i>=0;i--){
        for(int j=num2.size()-1;j>=0;j--){
            tmp=(num1[i]-'0')*(num2[j]-'0')+answer[i+j+1]+acarreo-'0';
            acarreo=tmp/10;
            answer[i+j+1]=(tmp%10)+'0';
        }   
        answer[i]=acarreo+'0';
    }

    return answer;
}

int main(){

    while(gets(num1)){
		gets(num2);
		cout<<mult()<<endl;
	}

    return 0;
}