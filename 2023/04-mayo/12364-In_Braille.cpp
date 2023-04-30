#include <bits/stdc++.h>

using namespace std;

int n;

char caracter,
    mat[10][500];

string cad;

map<int, vector<vector<char>>> braile;

void print_traslate(string cad)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = cad[j] - '0';
            cout << braile[c][i][0] << braile[c][i][1];
            if (j != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void init()
{
    braile[0] = {
        {'.', '*'},
        {'*', '*'},
        {'.', '.'}};
    braile[1] = {
        {'*', '.'},
        {'.', '.'},
        {'.', '.'}};
    braile[2] = {
        {'*', '.'},
        {'*', '.'},
        {'.', '.'}};
    braile[3] = {
        {'*', '*'},
        {'.', '.'},
        {'.', '.'}};
    braile[4] = {
        {'*', '*'},
        {'.', '*'},
        {'.', '.'}};
    braile[5] = {
        {'*', '.'},
        {'.', '*'},
        {'.', '.'}};
    braile[6] = {
        {'*', '*'},
        {'*', '.'},
        {'.', '.'}};
    braile[7] = {
        {'*', '*'},
        {'*', '*'},
        {'.', '.'}};
    braile[8] = {
        {'*', '.'},
        {'*', '*'},
        {'.', '.'}};
    braile[9] = {
        {'.', '*'},
        {'*', '.'},
        {'.', '.'}};
}

bool compara_braile(int pos_braile,int ini){
    for(int i=0;i<3;i++){
        for(int j=ini;j<ini+2;j++){
            if(braile[pos_braile][i][j-ini]!=mat[i][j]){
                return false;
            }
        }
    }
    return true;
}

void print_leter(int ini){
    for(int i=0;i<=9;i++){
        if(compara_braile(i,ini)){
            cout<<i;
            break;
        }
    }
}
int main()
{

    init();
    /*freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);*/
    while (cin >> n)
    {
        if(n==0){
            //cout<<"X"<<endl;
            break;
        }
        cin >> caracter;
        if (caracter == 'S')
        {
            cin >> cad;
            print_traslate(cad);
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < n * 2; j++)
                {
                    cin >> mat[i][j];
                }
            }
            for(int i=0;i<n;i++){
                print_leter(i*2);
            }
            cout<<endl;
        }
    }

    return 0;
}