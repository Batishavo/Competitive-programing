#include <bits/stdc++.h>

using namespace std;

int t,
    mile,
    juice,
    aux,
    n,
    query;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        juice = mile = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            int aux_mile = (aux / 30) + 1,
                aux_juice = (aux / 60) + 1;
            mile += aux_mile * 10;
            juice += aux_juice * 15;
        }
        //cout<< mile << " "<<juice << endl;
        printf("Case %d: ", ++query);
        if (juice < mile)
        {
            printf("Juice %d\n", juice);
        }
        else if (mile < juice)
        {
            printf("Mile %d\n", mile);
        }
        else
        {
            printf("Mile Juice %d\n", juice);
        }
    }

    return 0;
}