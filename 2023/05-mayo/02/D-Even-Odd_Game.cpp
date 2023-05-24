#include <bits/stdc++.h>

using namespace std;

int t;

long long n,
    alice,
    bob;

vector<long long> arr_even,
    arr_odd;

stack<long long> odd,
    even;

bool turn = true;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        arr_even.clear();
        arr_odd.clear();

        turn = true;

        alice = 0;
        bob = 0;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            long long aux;
            cin >> aux;
            if (aux % 2 == 0)
            {
                arr_even.push_back(aux);
            }
            else
            {
                arr_odd.push_back(aux);
            }
        }

        sort(arr_even.begin(), arr_even.end());
        //reverse(arr_even.begin(),arr_even.end());
        sort(arr_odd.begin(), arr_odd.end());
        //reverse(arr_odd.begin(), arr_odd.end());

        for(int i = 0; i < arr_even.size(); i++){
            even.push(arr_even[i]);
        }
        for(int i = 0; i < arr_odd.size(); i++){
            //cout<<arr_odd[i]<<endl;
            odd.push(arr_odd[i]);
        }

        while (!odd.empty() || !even.empty())
        {
            /*if(!odd.empty()){
                cout<<odd.top()<<" odd ";
            }
            if(!even.empty()){
                cout<<even.top()<<" even ";
            }
            cout<<endl;*/
            if (odd.empty())
            {
                if (turn)
                {
                    alice += even.top();
                }
                even.pop();
            }
            else if (even.empty())
            {
                if (!turn)
                {
                    bob += odd.top();
                }
                odd.pop();
            }
            else
            {
                if (turn)
                {
                    if (even.top() > odd.top())
                    {
                        alice += even.top();
                        even.pop();
                    }
                    else
                    {
                        odd.pop();
                    }
                }
                else
                {
                    if (odd.top() > even.top())
                    {
                        bob += odd.top();
                        odd.pop();
                    }
                    else
                    {
                        even.pop();
                    }
                }
            }
            turn = !turn;
        }

        //cout<<alice<<" "<<bob<<endl;

        if(alice>bob){
            cout<<"Alice\n";
        }
        else if(bob>alice){
            cout<<"Bob\n";
        }
        else{
            cout<<"Tie\n";
        }
    }

    return 0;
}