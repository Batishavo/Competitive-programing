#include <bits/stdc++.h>

using namespace std;

const int limit = 110;

struct teams
{

    int num_Team         = 0,
        solving_Problems = 0,
        penalty          = 0;

    teams(int num_Team, int solving_Problems, int penalty)
    {
        this->num_Team = num_Team;
        this->solving_Problems = solving_Problems;
        this->penalty = penalty;
    }

    void print_team()
    {
        cout << num_Team << " "
             << solving_Problems << " "
             << penalty << endl;
    }

    void update_num_team(int num_Team){
        this->num_Team = num_Team;
    }

};

int t,
    team,
    problem,
    penalty,
    wrong_answer[limit][15],
    penanty_acumulado[limit][15];

char request_Submission;

string submision;

teams constest_Teams[limit];

void asign_Values()
{
    string tmp;
    int actual;

    for (int i = 0; i < submision.size(); i++)
    {
        if (submision[i] == ' ')
        {
            switch (actual)
            {
            case 0:
                team = stoi(tmp);
                break;
            case 1:
                problem = stoi(tmp);
                break;
            default:
                penalty = stoi(tmp);
                request_Submission = submision[i + 1];
                return;
            }
            tmp = "";
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
    if(a.num_Team == 0){
        return false;
    }
    else if(a.solving_Problems== b.solving_Problems){
        if(a.penalty == b.penalty){
            return a.num_Team < b.num_Team;
        }
        return a.penalty<b.penalty;
    }
    return a.solving_Problems>b.solving_Problems;
}
void update_Right()
{
    constest_Teams[team] = {team};
}
void update_Wrong()
{

}
void update_Existing()
{
    constest_Teams[team].update_num_team(team);
}
void clean()
{
    for(int i = 0; i <=100;i++){
        constest_Teams[i]={0,0,0};
    }
}
int main()
{

    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--)
    {
        clean();
        while (getline(cin, submision) && submision.length() != 0)
        {
            asign_Values();
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
        sort(constest_Teams, constest_Teams+101, order);
        for (int i = 0; i <=100 ; i++)
        {   
            if(constest_Teams[i].num_Team == 0){
                break;
            }
            constest_Teams[i].print_team();
        }
    }

    return 0;
}