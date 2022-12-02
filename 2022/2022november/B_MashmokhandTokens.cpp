#include <bits/stdc++.h>

using namespace std;

long long n, a, b, aux;

long long binary(long long num)
{

    long long ini = 0, fin = num,
              mayor = num * a / b;

    while (ini < fin)
    {
        long long mid = ini + (fin - ini) / 2,
                  operation = mid * a / b;
        // cout<<"**"<<mid<<endl;
        if (operation == mayor)
        {
            fin = mid;
        }
        else
        {
            ini = mid + 1;
        }
    }
    return fin;
}

int main()
{

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        // cout << "--";
        cout << aux - binary(aux) << endl;
    }

    return 0;
}