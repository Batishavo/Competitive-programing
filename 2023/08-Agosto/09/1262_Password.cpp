#include <bits/stdc++.h>

using namespace std;

bool flag;
vector<string> all_paswords;
vector<string> valid_characters;

map<string, bool> used;

bool exist(char c, string mat2[], int pos)
{

    for (int i = 0; i < 6; i++)
    {
        if (mat2[i][pos] == c)
        {
            return true;
        }
    }
    return false;
}

vector<string> get_valid_characters(string mat1[], string mat2[])
{

    vector<string> valid_characters;

    for (int j = 0; j < 5; j++)
    {

        string cad_actual = "";

        for (int i = 0; i < 6; i++)
        {

            char character = mat1[i][j];

            if (exist(character, mat2, j))
            {
                cad_actual += character;
            }
        }

        valid_characters.push_back(cad_actual);
        if (cad_actual == "")
        {
            flag = false;
        }
    }

    return valid_characters;
}

void get_all_paswords(string actual)
{

    if (actual.size() == 5)
    {
        if (!used[actual])
        {
            used[actual] = 1;
            all_paswords.push_back(actual);
        }
        return;
    }

    int pos = actual.size();

    for (int i = 0; i < valid_characters[pos].size(); i++)
    {
        get_all_paswords(actual + valid_characters[pos][i]);
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int k;

    cin >> t;

    string mat1[10];
    string mat2[10];

    while (t--)
    {

        flag = true;

        cin >> k;

        for (int i = 0; i < 6; i++)
        {
            cin >> mat1[i];
        }

        for (int i = 0; i < 6; i++)
        {
            cin >> mat2[i];
        }

        valid_characters = get_valid_characters(mat1, mat2);

        if (!flag)
        {
            cout << "NO\n";
        }
        else
        {

            all_paswords.clear();
            used.clear();
            get_all_paswords("");

            if (all_paswords.size() >= k)
            {
                sort(all_paswords.begin(), all_paswords.end());
                cout << all_paswords[k - 1] << endl;
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}