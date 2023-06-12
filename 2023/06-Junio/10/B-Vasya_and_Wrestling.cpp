#include <bits/stdc++.h>

using namespace std;

int n;

vector<long long> first_player,
    second_player;

long long first_points,
    second_points,
    num;

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &num);
        if (num > 0)
        {
            first_points += num;
            first_player.push_back(num);
        }
        else
        {
            second_points += -num;
            second_player.push_back(-num);
        }
    }

    if (first_points == second_points)
    {

        int p1 = 0;
        bool flag = false;

        while (p1 < first_player.size() && p1 < second_player.size())
        {

            //cout<<first_player[p1] <<" "<<second_player[p1]<<endl;

            if (first_player[p1] > second_player[p1])
            {
                flag = true;
                cout << "first" << endl;
                break;
            }
            else if (first_player[p1] < second_player[p1])
            {
                flag = true;
                cout << "second" << endl;
                break;
            }
            p1++;
        }

        //cout<<"--------"<<endl;

        if (!flag)
        {
            if (first_player.size() != second_player.size())
            {
                if (first_player.size() > second_player.size())
                {
                    cout << "first" << endl;
                }
                else
                {
                    cout << "second" << endl;
                }
            }
            else
            {
                if (num < 0)
                {
                    cout << "second" << endl;
                }
                else
                {
                    cout << "first" << endl;
                }
            }
        }
    }
    else
    {
        if (first_points > second_points)
        {
            cout << "first" << endl;
        }
        else
        {
            cout << "second" << endl;
        }
    }

    return 0;
}