#include <bits/stdc++.h>

using namespace std;

typedef map<string, int> mpsi;
typedef unsigned long long ull;

struct my
{
    string x;
    int byte;
    ull result;
};

my ar[330];

ull power(int dui, int p)
{
    ull r = 1;

    for (int i = 1; i <= p; i++)
    {
        r *= dui;
    }

    return r;
}

ull decimal(string s)
{
    //    ull ret = 0;
    //    int len = s.length () - 1;
    //
    //    for ( int i = len; i >= 0; i-- )
    //        ret += (power (2, i) * (s [len - i] - '0'));
    //
    //    return ret;

    ull ret = 0, k;
    int len = s.length();
    int p = len - 1;

    for (int i = 0; i < len and p >= 0; i++)
    {
        k = (s[i] - '0') * power(2, p);

        ret += k;
        p--;
    }

    return ret;
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int b, v;
    mpsi mp;
    while (cin >> b >> v)
    {
        mp.clear();

        string s;
        int i, y, line = 0, arlen = 1;

        for (i = 0; i < v; i++)
        {
            cin >> s >> y;
            // cout << s << " " << y << "\n" ;
            line += y;
            mp[s] = arlen;
            ar[arlen].x = s;
            ar[arlen].byte = y;
            arlen++;
        }

        int indx = 1, cnt = 0;
        string ans = "";

        for (i = 0, cnt = 1; i < line; i++, cnt++)
        {
            cin >> s;
            // cout << cnt << " ; ";

            ans += s;

            if (cnt == ar[indx].byte)
            {
                cnt = 0;
                ar[indx].result = decimal(ans);
                indx++;
                ans = "";
            }
        }

        int q;
        // cout << "query: ";
        cin >> q;
        while (q--)
        {
            cin >> s;
            // cout <<mp[s] << "\n";
            if (mp[s])
            {
                // int in = mp[s];
                // cout << in << "\n";
                cout << s << "=" << ar[mp[s]].result << "\n";
            }

            else
            {
                cout << s << "="
                     << "\n";
            }
        }
    }

    return 0;
}