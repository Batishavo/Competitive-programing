#include <bits/stdc++.h>

using namespace std;

int dowload(
    int actual_Station
    ,vector<stack<int>> &station
    ,int s
    ,int q
    ,stack<int> &cargo
){

    int num = 0;

    while(station[actual_Station].size()<q && !cargo.empty()){
        if(cargo.top()!=actual_Station){
            station[actual_Station].push(cargo.top());
        }
        cargo.pop();
        num++;
    }  

    while(!cargo.empty() && cargo.top()==actual_Station){
        cargo.pop();
        num++;
    }

    return num;
}

int load(
    stack<int> &station
){

}

int move(){

}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int actual_Station,
        flag,
        n,
        q,
        s,
        sum,
        test_Case;

    vector<stack<int>> station;
    vector<int> memo(110);

    cin >> test_Case;

    while (test_Case--)
    {

        stack<int> cargo;
        fill(memo.begin(), memo.end(),0);
        actual_Station = 1;
        sum = 0;

        station.clear();

        cin >> n >> s >> q;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            stack<int> actual;
            for (int j = 0; j < num; j++)
            {
                int aux;
                cin >> aux;
                actual.push(aux);
                if(memo[aux]!=0){
                    flag++;
                }
                memo[aux]++;
            }

            station.push_back(actual);
        }

        while (flag!=0)
        {
            
            sum+=dowload(actual_Station,station,q,s,cargo);
            sum+=load(station[actual_Station]);
            if(flag!=0){
                sum+=move();
            }
        
        }

        cout<<sum<<endl;
    }

    return 0;
}