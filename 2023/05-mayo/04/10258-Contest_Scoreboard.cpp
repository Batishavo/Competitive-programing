#include <bits/stdc++.h>

using namespace std;

const int limit = 110;

struct teams
{

    int num_Team = 0,
        solving_Problems = 0,
        penalty = 0;

    teams(int num_Team, int solving_Problems, int penalty)
    {
        this->num_Team = num_Team;
        this->solving_Problems = solving_Problems;
        this->penalty = penalty;
    }

    teams(){
        this->num_Team = 0;
        this->solving_Problems = 0;
        this->penalty = 0;
    }

    void print_team()
    {
        cout << num_Team << " "
             << solving_Problems << " "
             << penalty << endl;
    }

    void update_num_team(int num_Team)
    {
        this->num_Team = num_Team;
    }
};

int t,
    team,
    problem,
    penalty,
    right_answer[limit][15],
    penalty_acumulado[limit][15];

char request_Submission;

string submision;

teams constest_Teams[limit];

void asign_Values()
{
    string tmp;
    int actual=0,
        long_cad=submision.size();
    request_Submission=submision[long_cad-1];

    for (int i = 0; i < long_cad; i++)
    {
        if (submision[i] == ' ')
        {
            //cout<<tmp<<endl;
            switch (actual)
            {
            case 0:
                team = stoi(tmp);
                break;
            case 1:
                problem = stoi(tmp);
                break;
            case 2:
                penalty = stoi(tmp);
                //request_Submission = submision[i + 1];
                return;
            }
            tmp = "";
            actual++;
        }
        else
        {
            tmp += submision[i];
        }
    }
}

// Todo: el ordenamineto
bool order(teams a, teams b)
{
    if (a.solving_Problems == b.solving_Problems)
    {
        if (a.penalty == b.penalty)
        {
            return a.num_Team < b.num_Team;
        }
        return a.penalty < b.penalty;
    }
    return a.solving_Problems > b.solving_Problems;
}
void update_Existing()
{
    constest_Teams[team].update_num_team(team);
}
void update_Wrong()
{
    update_Existing();
    int aux = penalty -penalty_acumulado[team][problem];
    penalty_acumulado[team][problem]+=aux;
}
void update_Right()
{
    if(right_answer[team][problem]==0){
        update_Wrong();
        right_answer[team][problem]=1;
        int team_Penalty = constest_Teams[team].penalty+penalty_acumulado[team][problem],
            team_problem = constest_Teams[team].solving_Problems+1;
        constest_Teams[team]={team,team_Penalty,team_problem};
    }
}

void clean()
{
    for (int i = 0; i <= 100; i++)
    {
        constest_Teams[i] = {0, 0, 0};
        for(int j=1;j<=10;j++){
            right_answer[i][j] = 0;
            penalty_acumulado[i][j]=0;
        }
    }
}
int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--)
    {
        clean();
        while (getline(cin, submision) && submision.length() != 0)
        {
            asign_Values();
            // cout<<team<<" "<<problem<<" "<<penalty<<endl;
            // cout<<request_Submission<<endl;
            cout<<submision<<endl;
            switch (request_Submission)
            {
            case 'I':

                update_Right();

                break;
            case 'C':

                update_Wrong();

                break;
            default:
                update_Existing();
                break;
            }
        }
        sort(constest_Teams, constest_Teams + 101, order);
        for (int i = 0; i <= 100; i++)
        {
            if (constest_Teams[i].num_Team == 0)
            {
                continue;
            }
            constest_Teams[i].print_team();
        }
        clean();
    }

    return 0;
}