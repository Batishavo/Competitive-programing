#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> combinados['Z' + 10];

string s = "COPAOAORSHCEDQGHBAGJFBETQNRHPQMNIOMCABKGHBDLDCJTJPKFBQIPJDONRJKAIGFTDDFNQLIKRIJGKQQENBCJTIRIQFKGMJNB";

int k = 9;

int main()
{
    freopen("salida.txt", "w", stdout);

    for (int i = 'A'; i <= 'Z'; i++)
    {
        combinados[i].clear();
    }

    int ini = 0,
        answer = 0,
        aux = s.size();

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            combinados[s[i - 1]].push_back({ini, i - 1});
            answer = max(answer, i - ini + k);
            ini = i;
        }
    }

    combinados[s[aux - 1]].push_back({ini, aux - 1});
    answer = max(answer, aux - ini + k);

    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (combinados[i].size() >= 1)
        {

            cout << char(i) << endl;
            for (int j = 0; j < combinados[i].size(); j++)
            {
                cout << combinados[i][j].first << " " << combinados[i][j].second << endl;
            }
            cout << "--" << endl;
            int lon = k,
                p1 = 0,
                sum = combinados[i][0].second - combinados[i][0].first + 1;
            for (int j = 1; j < combinados[i].size(); j++)
            {

                sum += combinados[i][j].second - combinados[i][j].first + 1;

                int dif = combinados[i][j].first - combinados[i][j - 1].second - 1;

                if (lon >= dif)
                {
                    lon -= dif;
                }
                else
                {
                    if (dif > k)
                    {
                        p1 = j;
                        sum = combinados[i][j].second - combinados[i][j].first + 1;
                        lon = k;
                    }
                    else
                    {
                        while (p1 < j && dif > lon)
                        {

                            sum -= combinados[i][p1].second - combinados[i][p1].first + 1;

                            lon += combinados[i][p1 + 1].first - combinados[i][p1].second - 1;

                            p1++;
                        }
                    }
                }
                cout << sum << " " << k << endl;
                answer = max(answer, sum + k);
            }
        }
    }

    cout << "**" << answer << endl;

    return 0;
}