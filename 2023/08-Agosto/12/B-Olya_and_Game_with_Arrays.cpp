#include <bits/stdc++.h>

using namespace std;

const int limit = 25010;

vector<long long> arr[limit];

void clean(int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].clear();
    }
}

long long get_sum(int pos)
{

    long long sum = 0;
    int ini;

    if (arr[pos][0] == arr[pos][1])
    {
        ini = 1;
    }
    else
    {
        ini = 0;
    }

    if(ini==0){
        return arr[pos][0];
    }

    for (int i = ini; i < arr[pos].size(); i++)
    {
        if (arr[i] != arr[i - 1])
        {
            break;
        }
        sum += arr[pos][i];
    }

    return sum;
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int m;
    int pos_menor;

    long long answer;
    long long menor_sum;

    cin >> t;

    while (t--)
    {

        answer = 0;

        cin >> n;

        for (int i = 0; i < n; i++)
        {

            cin >> m;

            for (int i = 0; i < m; i++)
            {
                int aux;
                cin >> aux;
                arr[i].push_back(aux);
            }
            sort(arr[i].begin(), arr[i].end());
        }

        pos_menor = 0;
        menor_sum = get_sum(0);

        for (int i = 1; i < n; i++)
        {

            long long actual_sum = get_sum(i);
            // bool actual_one_num = arr[i][0] != arr[i][1];
            if (menor_sum > actual_sum)
            {
                menor_sum = actual_sum;
                pos_menor = i;
            }
        }

        long long sumtmp = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            long long tmp = arr[i][0];
            for (int j = 1; j < arr[i].size(); i++)
            {
                if (arr[i][j] != arr[i][j - 1])
                {
                    break;
                }
                tmp += arr[i][j];
            }
            sumtmp = min(sumtmp, tmp);
        }

        answer += sumtmp;

        for (int i = 0; i < n; i++)
        {
            if (i != pos_menor)
            {
                answer += get_sum(i);
            }
        }

        cout << answer << endl;

        clean(n);
    }

    return 0;
}