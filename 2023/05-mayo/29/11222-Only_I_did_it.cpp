#include <bits/stdc++.h>

using namespace std;

const int limit = 10e4;

int t,
    problems[5][limit + 5],
    cantidad[5],
    cont,
    maximo;

void clean()
{
    maximo = 0;
    for (int i = 0; i < 3; i++)
    {
        cantidad[i] = 0;
    }

    for (int i = 1; i <= limit; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            problems[j][i] = 0;
        }
    }
}

bool isUnique(int i)
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        sum += problems[j][i];
    }

    return sum == 1;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            int num;
            scanf("%d", &num);
            for (int j = 0; j < num; j++)
            {
                int aux;
                scanf("%d", &aux);
                problems[i][aux] = 1;
            }
        }

        for (int i = 1; i <= limit; i++)
        {

            if (isUnique(i))
            {
                for (int j = 0; j < 3; j++)
                {
                    if (problems[j][i] == 1)
                    {
                        cantidad[j]++;
                        break;
                    }
                }
            }
        }

        //printf("Hola mundo");
        
        for (int i = 0; i < 3; i++)
        {
            maximo = max(maximo, cantidad[i]);
        }

        printf("Case #%d:\n", ++cont);

        for (int i = 0; i < 3; i++)
        {
            if (cantidad[i] == maximo)
            {
                printf("%d %d", i + 1, maximo);
                for (int j = 1; j <= limit; j++)
                {
                    if (problems[i][j] && isUnique(j))
                    {
                        printf(" %d", j);
                    }
                }
                printf("\n");
            }
        }

        clean();
    }

    return 0;
}