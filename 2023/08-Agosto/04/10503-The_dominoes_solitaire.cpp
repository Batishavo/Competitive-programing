#include <bits/stdc++.h>

using namespace std;

int n;
int m;

pair<int, int> first_piece;
pair<int, int> last_piece;

vector<bool> memo(20, 0);
vector<pair<int, int>> pieces(20);

bool flag = 0;

void posible_to_solve(int pos, int comp)
{

    if (flag)
    {
        return;
    }

    if (pos >= n)
    {

        for(int i=0;i<m;i++)
        {
          if(memo[i]==0 && pieces[i].first==comp && pieces[i].second==last_piece.first ){
            flag = true;
            break;
          }
          if(memo[i]==0 && pieces[i].second==comp && pieces[i].first==last_piece.first ){
            flag = true;
            break;
          }
        }
        return;
    }

    for (int i = 0; i < m; i++)
    {

        if (memo[i] != 0)
        {
            continue;
        }

        if (comp == pieces[i].first || comp==pieces[i].second)
        {

            memo[i] = 1;

            //printf("%d %d %d\n",pos+1,pieces[i].first,pieces[i].second);


            int num = (pieces[i].first==comp)?pieces[i].second : pieces[i].first;
            
            posible_to_solve(pos + 1,num);

            memo[i] = 0;
        }
    }

    return;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (cin >> n)
    {

        if (n == 0)
        {
            break;
        }

        cin >> m;

        cin >> first_piece.first >> first_piece.second;
        cin >> last_piece.first >> last_piece.second;

        for (int i = 0; i < m; i++)
        {

            cin >> pieces[i].first >> pieces[i].second;
        }

        flag = false;
        // printf("0 %d %d\n", first_piece.first, first_piece.second);
        // posible_to_solve(0, first_piece.first);
       //printf("0 %d %d\n", first_piece.second,first_piece.first );
        posible_to_solve(1, first_piece.second);

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        for (int i = 0; i < m; i++)
        {
            memo[i] = 0;
        }
    }

    return 0;
}