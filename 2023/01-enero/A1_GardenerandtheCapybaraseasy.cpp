#include <bits/stdc++.h>

using namespace std;

int t;
string cad, c1, c2, c3;

bool posibles()
{
    string t1, t2, t3;
    for (int i = 0; i < cad.size() - 2; i++)
    {
        t1 = cad.substr(0, i + 1);
        //cout<<i<<" T1 :"<<t1<<endl;
        int pos=1;
        for (int j = i + 1; j < cad.size() - 1; j++)
        {
            //f(j==cad.size())continue;
            t2 = cad.substr(i + 1, pos);
            //cout<<j<<" T2 :"<<t2<<endl;
            pos++;
            t3 = cad.substr(j + 1);
            //printf("%d %d\n", i, j);
            //cout << t1 << " " << t2 << " " << t3 << endl;
            if ((string(t1) <= string(t2) && string(t3) <= string(t2)) ||
                (string(t2) <= string(t1) && string(t2) <= string(t3)))
            {
                c1=t1;
                c2=t2;
                c3=t3;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> cad;
        if (posibles())
        {
            cout << c1 << " " << c2 << " " << c3 << endl;
        }
        else
        {
            cout << ":(" << endl;
        }
    }

    return 0;
}