#include <bits/stdc++.h>

using namespace std;

const int alpabet = 'Z' + 10;

string cards[20],
    aux;

char tipos[5] = {'S', 'H', 'D', 'C'};

int suma,
    especial,
    cantidad[alpabet];

bool K[alpabet],
    Q[alpabet],
    J[alpabet],
    A[alpabet],
    trump[5];

int rule1()
{
    int sum = 0;
    for (int i = 0; i < 13; i++)
    {
        if (cards[i][0] == 'A')
        {
            A[cards[i][1]] = true;
            sum += 4;
        }
        else if (cards[i][0] == 'K')
        {
            K[cards[i][1]] = true;
            sum += 3;
        }
        else if (cards[i][0] == 'Q')
        {
            Q[cards[i][1]] = true;
            sum += 2;
        }
        else if (cards[i][0] == 'J')
        {
            J[cards[i][1]] = true;
            sum++;
        }
        cantidad[cards[i][1]]++;
        // cout<<cards[i][1]<<endl;
    }
    return sum;
}

int rule2_4()
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        if (A[tipos[i]])
        {
            trump[i] = 1;
        }

        if (K[tipos[i]] && cantidad[tipos[i]] < 2)
        {
            res++;
        }
        else if (K[tipos[i]])
        {
            trump[i] = 1;
        }
        if (Q[tipos[i]] && cantidad[tipos[i]] < 3)
        {
            res++;
        }
        else if (Q[tipos[i]])
        {
            trump[i] = 1;
        }
        if (J[tipos[i]] && cantidad[tipos[i]] < 4)
        {
            res++;
        }
    }
    return res;
}

int rule5_7()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        if (
            cantidad[tipos[i]] < 2)
        {
            sum += 2;
        }
        else if (cantidad[tipos[i]] == 2)
        {
            sum++;
        }
    }
    //cout<<sum<<endl;
    return sum;
}

void cleanup()
{
    for (int i = 0; i < 4; i++)
    {
        cantidad[tipos[i]] = 0;
        K[tipos[i]] = 0;
        Q[tipos[i]] = 0;
        J[tipos[i]] = 0;
        A[tipos[i]] = 0;
        trump[i] = false;
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (cin >> aux)
    {
        cards[0] = aux;
        suma = 0;
        especial = 0;
        for (int i = 1; i < 13; i++)
        {
            cin >> cards[i];
        }
        suma += rule1();
        //cout<<suma<<endl;
        suma -= rule2_4();
        //cout<<suma<<endl;
        especial += rule5_7();
        //cout<<rule5_7()<<endl;
        /*cout<<
            rule1()<<endl<<
            rule2_4()<<endl<<
            rule5_7()<<endl;

        cout<<
            suma    <<" "<<
            trump[0]<<" "<<
            trump[1]<<" "<<
            trump[2]<<" "<<
            trump[3]<<" "<<
        endl;*/        
        if (
            trump[0] &&
            trump[1] &&
            trump[2] &&
            trump[3] &&
            suma >= 16)
        {
            cout << "BID NO-TRUMP" << endl;
        }
        else if(suma + especial>=14)
        {
            char letra = 'S';
            int mayor = cantidad['S'];
            for (int i = 1; i < 4; i++)
            {
                if (cantidad[tipos[i]] > mayor)
                {
                    mayor = cantidad[tipos[i]];
                    letra = tipos[i];
                }
            }

            cout << "BID " << letra << endl;
        }
        else {
            cout << "PASS" << endl;
        }
        cleanup();
    }

    return 0;
}