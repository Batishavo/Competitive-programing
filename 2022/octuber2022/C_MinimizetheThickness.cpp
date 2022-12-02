#include <bits/stdc++.h>

using namespace std;

int t, n,
    arr[2005];

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n;

        int menor = n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i < n; i++)
        {

            long long cont = 0,
                      aux = 0;

            int comp = i,
                l = i-1;

            bool flag = false;

            for (int j = 0; j < i; j++)
            {
                cont += arr[j];
            }
            // printf("cont :%lld\n",cont);
            //printf("comp :%d\n",comp);
            for (int j = i; j < n; j++)
            {
                aux += arr[j];
                if (aux > cont)
                {
                    break;
                }
                else if (aux == cont)
                {
                    // printf("aux :%lld\n",aux);
                    //printf("r-l :%d j: %d l: %d\n",j-l,j,l);
                    comp = max(comp, j - l);
                    l = j ;
                    aux = 0;
                    if (j == n - 1)
                    {
                        flag = true;
                    }
                }
            }

            if (flag)
            {
                menor = min(menor, comp);
            }
        }
        cout << menor << endl;
    }

    return 0;
}