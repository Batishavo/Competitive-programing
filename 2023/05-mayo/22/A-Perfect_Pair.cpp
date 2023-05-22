#include <bits/stdc++.h>

using namespace std;

long long x,
    y,
    m;

unsigned long long sumas(long long menor, long long mayor)
{
    unsigned long long sum = mayor,
                       cont = 0;

    if (menor < 0)
    {
        unsigned long long num = (abs(menor) / mayor) + (abs(menor) % mayor==0?0:1);
        cont += num;
        menor += mayor * num;
        //cout << num <<" "<<menor<<" "<< endl;
    }
    else if (menor == 0)
    {
        cont++;
        menor = mayor;
    }
    while (sum < m)
    {
        sum += menor;
        menor = mayor;
        mayor = sum;
        cont++;
    }
    return cont;
}

int main()
{

    cin >> x >> y >> m;

    if (x >= m || y >= m)
    {
        cout << "0\n";
    }
    else if (x <= 0 && y <= 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << sumas(min(x, y), max(x, y)) << endl;
    }

    return 0;
}