#include <bits/stdc++.h>

using namespace std;

const int limit = 10e4;

int values[limit][4];

string cars[limit];

string car_name(int price,int n){

    int total=0;
    string answer;

    for(int i=0;i<n;i++){
        if(values[i][0]<=price && price<=values[i][1]){
            total++;
            answer = cars[i];
        }
    }

    if(total==1){
        return answer;
    }
    return "UNDETERMINED";

}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int query;
    bool flag = false;

    cin >> t;

    while (t--)
    {
        if(flag){
            cout<<endl;
        }
        else{
            flag = !flag;
        }

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> cars[i] >> values[i][0] >> values[i][1];
        }

        cin >> query;

        for (int i = 0; i < query; i++)
        {
            int price;
            cin >> price;
            cout<<car_name(price,n)<<endl;
        }
    }

    return 0;
}