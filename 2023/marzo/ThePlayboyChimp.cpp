#include <bits/stdc++.h>

using namespace std;

vector<long long> ladys;

long long aux;

int n,
    q;

void bynary_search()
{

    int ini = 0,
        fin = n - 1;

    while (ini <= fin)
    {
        int mid = ((ini + fin) / 2) + 1;

        if (ladys[mid] == aux)
        {
            cout << ladys[mid - 1] << " " << ladys[mid + 1] << endl;
            break;
        }
        else if (ladys[mid] < aux && ladys[mid + 1] > aux)
        {
            cout << ladys[mid] << " " << ladys[mid + 1] << endl;
            break;
        }
        else if (ladys[mid - 1] < aux && ladys[mid] > aux)
        {
            cout << ladys[mid - 1] << " " << ladys[mid] << endl;
            break;
        }
        else if (ladys[mid] > aux)
        {
            fin = mid - 1;
        }
        else
        {
            ini = mid;
        }
        // cout << mid << endl;
    }
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    cin >> n;
    long long ant = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux != ant)
            ladys.push_back(aux);
        ant = aux;
    }
    n=ladys.size();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> aux;
        if (aux > ladys[0] && aux < ladys[n - 1])
        {
            bynary_search();
        }
        else
        {
            if(n==1 & aux==ladys[0]){
                cout<<"X X"<<endl;
            }
            else if (aux < ladys[0])
            {
                cout << "X"
                     << " " << ladys[0] << endl;
            }
            else if (aux == ladys[0])
            {
                cout << "X"
                     << " " << ladys[1] << endl;
            }
            else if (aux == ladys[n - 1])
            {
                cout << ladys[n - 2] << " "
                     << "X" << endl;
            }
            else
            {
                cout << ladys[n - 1] << " "
                     << "X" << endl;
            }
        }
    }

    return 0;
}