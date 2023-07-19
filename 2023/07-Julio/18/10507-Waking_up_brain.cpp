#include <bits/stdc++.h>

using namespace std;

const int limit = 'Z' + 10;

bool adjacent_mat[limit][limit];
bool turn_on[limit];
bool use[limit];

void clean_adjacent_mat()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        for (int j = 'A'; j <= 'Z'; j++)
        {
            adjacent_mat[i][j] = 0;
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        use[i] = 0;
        turn_on[i] = 0;
    }
}

bool all_aweken()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (turn_on[i] != use[i])
        {
            return false;
        }
    }
    return true;
}

bool can_be_turn_on(int pos)
{
    int cont = 0;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (adjacent_mat[pos][i] == 1 && turn_on[i] == 1)
        {
            cont++;
        }
    }
    return cont >= 3;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int conections;
    int slep_areas;

    string cad;

    while (cin >> n)
    {
        slep_areas=0;
        clean_adjacent_mat();
        cin >> conections >> cad;
        for (int i = 0; i < conections; i++)
        {
            string vertice;
            cin >> vertice;
            adjacent_mat[vertice[0]][vertice[1]] = 1;
            adjacent_mat[vertice[1]][vertice[0]] = 1;
            if(use[vertice[0]]==0){
                slep_areas++;
            }
            if(use[vertice[1]]==0){
                slep_areas++;
            }
            use[vertice[0]] = 1;
            use[vertice[1]] = 1;
        }

        for (int i = 0; i < cad.size(); i++)
        {
            if(use[cad[i]]==0){
                slep_areas++;
            }
            use[cad[i]] = 1;
            turn_on[cad[i]] = 1;
        }

        bool flag = true;
        int answer = 0;

        //cout<<slep_areas<<" "<<n<<endl;

        if(slep_areas<n){
            flag = false;
        }

        while (flag)
        {
            queue<int> new_turn_on;
            if (all_aweken())
            {
                break;
            }
            flag = false;
            for (int i = 'A'; i <= 'Z'; i++)
            {
                if (turn_on[i] != use[i])
                {
                    if (can_be_turn_on(i))
                    {
                        flag = true;
                        new_turn_on.push(i);
                    }
                }
            }
            answer++;
            while (!new_turn_on.empty())
            {
                turn_on[new_turn_on.front()] = 1;
                new_turn_on.pop();
            }
        }
        if (flag)
        {
            printf("WAKE UP IN, %d, YEARS\n", answer);
        }
        else
        {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
    }

    return 0;
}