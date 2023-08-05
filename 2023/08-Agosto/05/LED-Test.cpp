#include <bits/stdc++.h>

using namespace std;

int n;

string cads[15];

map<string, int> led;
map<string,bool>used;

bool flag;

void all_combination
    (
        vector<string>acumulado
        ,string actual
        ,int pos
    )
{

    if(pos==7){
        return acumulado;
    }

    for(int i=pos;i<7;i++){
        if(actual[i]=='N'){
            actual[i]='Y';
            if(led[actual]!=0 && used[actual]!=0){
                acumulado.push(actual); 
            }
        }
    }

}

bool dp(string ante,int pos){



}

void comp(string cad1,string cad2){

    int num1=led[cad1];

    


}

int main()
{

    led["YYYYYYN"] = 10;
    led["NYYNNNN"] = 1;
    led["YYNYYNY"] = 2;
    led["YYYYNNY"] = 3;
    led["NYYNNYY"] = 4;
    led["YNYYNYY"] = 5;
    led["YNYYYYY"] = 6;
    led["YYYNNNN"] = 7;
    led["YYYYYYY"] = 8;
    led["YYYYNYY"] = 9;

    while (cin >> n)
    {

        if (n == 0)
        {
            break;
        }

        flag = false;

        for (int i = 0; i < n; i++)
        {
            cin >> cad[i];
        }

        if (n == 1)
        {
            cout << "MATCH";
        }
        else
        {

            comp(cad[0],cad[n-1]);

            if (flag)
            {
                cout << "MATCH\n";
            }
            else
            {
                cout << "MISMATCH\n";
            }
        }
    }

    return 0;
}