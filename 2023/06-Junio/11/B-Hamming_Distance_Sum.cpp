#include <bits/stdc++.h>

using namespace std;

const int limit = 20e5 + 10;

string cad1,
    cad2;

int arr[limit][5];

long long cont = 0;

int left(int pos)
{

    int cad = cad1.size() - 2,
        num = pos + cad;

    if (num >= cad2.size())
    {
        // cout << "y1";
        return num - cad2.size() + 1;
    }
    // cout << "y2";
    return 0;
}

int right(int pos)
{
    // cout << " ";
    int cad = cad1.size() - 2,
        num = pos - cad;

    if (num < 1)
    {
        // cout << "x1";
        return cad1.size() + num - 2;
    }
    // cout << "x2";
    return cad1.size() - 1;
}

int sum(int pos)
{

    int pos_left = left(pos),
        pos_right = right(pos),
        tmp = 0;

    // cout << " " << pos_left  << " " << pos_right << " " << pos << endl;

    if (cad2[pos] == '0')
    {
        tmp = 1;
    }
    // cout<<tmp<<endl;
    return arr[pos_right][tmp] - arr[pos_left][tmp];
}

int main()
{

    cin >> cad1 >> cad2;

    cad1 = '*' + cad1;
    cad2 = '*' + cad2;

    for (int i = 1; i < cad1.size(); i++)
    {
        arr[i][0] = arr[i - 1][0];
        arr[i][1] = arr[i - 1][1];
        arr[i][cad1[i] - '0']++;
    }

    /* for(int i=0;i<cad1.size();i++){
         cout<<arr[i][0]<<" ";
     }
     cout<<endl;
     for(int i=0;i<cad1.size();i++){
         cout<<arr[i][1]<<" ";
     }
     cout<<endl;*/

    for (int i = 1; i < cad2.size(); i++)
    {
        cont += sum(i);
    }

    cout << cont << endl;

    return 0;
}