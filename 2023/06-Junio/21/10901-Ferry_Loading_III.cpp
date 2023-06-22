#include <bits/stdc++.h>

using namespace std;

int memo[10010];

void move_cars(
    int max_capacity
    ,queue<pair<int, int>> &my_Queue
    ,int my_Time
    ,int n
    ,int t
){
    while (!my_Queue.empty() && max_capacity &&  my_Queue.front().second<=my_Time) 
    {
        memo[my_Queue.front().first] = my_Time + t;
        my_Queue.pop();
        max_capacity--;
    }
}

int main()
{
    int test,
        n,
        t,
        m,
        my_Time;

    bool flag = 0,
         ferry_Positon;

    queue<pair<int, int>> my_Left,
        my_Right;

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    
    cin >> test;
    
    while (test--)
    {

        if (!flag)
        {
            flag = 1;
        }
        else
        {
            cout << endl;
        }

        cin >> n >> t >> m;

        for (int i = 0; i < m; i++)
        {
            int num;
            string cad;

            cin >> num >> cad;

            if (cad == "left")
            {
                my_Left.push({i, num});
            }
            else
            {
                my_Right.push({i, num});
            }
        }

        my_Time = 0;
        ferry_Positon = 1;

        while (!my_Left.empty() || !my_Right.empty())
        {

            int close=0;
            if(my_Left.empty()){
                close = my_Right.front().second;
            }
            else if(my_Right.empty()){
                close = my_Left.front().second;
            }
            else{
                close =min(my_Left.front().second,my_Right.front().second);
            }
            my_Time=max(my_Time,close);
            
            if (ferry_Positon)
            {

                move_cars(n, my_Left,my_Time,n,t);
            }
            else
            {
                move_cars(n, my_Right,my_Time,n,t);
            }

            ferry_Positon = !ferry_Positon;
            my_Time += t;
        }
        for (int i = 0; i < m; i++)
        {
            cout << memo[i] << endl;
        }
    }

    return 0;
}