#include <bits/stdc++.h>

using namespace std;

const long long limit = 10e13;

string cad;

long long price,
    tmpPrice,
    ned[5],
    posesion[5],
    cost[5],
    actual[5];

bool posible(long long num)
{

    tmpPrice = price;

    for (int i = 1; i <= 3; i++)
    {
        actual[i] = ned[i] * num;
    }
    for (int i = 1; i <= 3; i++)
    {
        actual[i] = actual[i] - posesion[i] >= 0 ? actual[i] - posesion[i] : 0;
    }
    for (int i = 1; i <= 3; i++)
    {
        tmpPrice -= actual[i] * cost[i];
    }
    return tmpPrice >= 0;
}

long long binarySearch()
{

    long long ini = 0,
              fin = limit;

    while (ini < fin)
    {

        long long mid = (ini+fin) / 2 + 1;

        //cout<<mid<<" "<<posible(mid)<<" "<<ini<<" "<<fin<< endl;

        if (posible(mid))
        {
            ini = mid;
        }
        else
        {
            fin = mid - 1;
        }
    }

    return ini;
}

int main()
{

    cin >> cad;

    for (int i = 1; i <= 3; i++)
    {
        cin >> posesion[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        cin >> cost[i];
    }
    cin >> price;

    for (int i = 0; i < cad.size(); i++)
    {
        switch (cad[i])
        {
            {
            case 'B':
                ned[1]++;
                break;
            case 'S':
                ned[2]++;
                break;
            default:
                ned[3]++;
                break;
            }
        }
    }
    //cout << "--";
    cout << binarySearch() << endl;
    return 0;
}