#include <bits/stdc++.h>

using namespace std;

string mat[5];

bool win(char caracter)
{   

    int num=0,
        num2=0;

    for(int i=0;i<3;i++){
        num=0;
        num2=0;
        for(int j=0;j<3;j++){
            if(mat[i][j]==caracter){
                num++;
            }
            if(mat[j][i]==caracter){
                num2++;
            }
        }

        if(num==3 || num2==3){
            return true;
        }
    }
    return false;
}

int main()
{

    int t, x, o;

    bool valid;

    cin >> t;

    while (t--)
    {

        x = 0;
        o = 0;

        valid = true;

        for (int i = 0; i < 3; i++)
        {
            cin >> mat[i];
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != 'O' && mat[i][j] != 'X' && mat[i][j] != '.')
                {
                    valid = false;
                }
                else if (mat[i][j] == 'X')
                {
                    x++;
                }
                else if (mat[i][j] == 'O')
                {
                    o++;
                }
            }
        }
        // cout<<x-o<<endl;
        if (valid && x - o >= 0 && x - o <= 1)
        {
            if (win('X') && win('O'))
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "yes";
            }
        }
        else
        {
            cout << "no";
        }
        cout << endl;
    }

    return 0;
}