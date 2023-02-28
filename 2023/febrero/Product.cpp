#include <bits/stdc++.h>

using namespace std;
string num1,
    num2;
char string1[300];
char string2[300];
string mul()
{
    string cad = "";
    vector<vector<int>> sum(num1.size() + 10);
    int acarreo = 0,
        pos = 0,
        mayor = 0;
    // cout << "Yella";
    for (int i = num2.size() - 1; i >= 0; i--)
    {

        for (int j = 0; j < pos; j++)
        {
            sum[i].push_back(0);
        }
        for (int j = num1.size() - 1; j >= 0; j--)
        {
            int tmp = ((num2[i] - '0') * (num1[j] - '0')) + acarreo;
            acarreo = tmp / 10;
            // printf("n1:%d n2: %d a: %d t: %d t/10: %d\n", num2[i] - '0', num1[j] - '0', acarreo, tmp, tmp / 10);
            sum[i].push_back(tmp % 10);
            // cout<<"-------";
            // system("pause");
        }
        while (acarreo > 0)
        {
            sum[i].push_back(acarreo % 10);
            acarreo /= 10;
        }
        int n = sum[i].size();
        mayor = max(mayor, n);
        pos++;
    }
    for (int i = 0; i < sum.size(); i++)
    {
        while (sum[i].size() < mayor)
        {
            sum[i].push_back(0);
        }
    }
    // for (int i = num1.size()-1;i>=0; i--)
    // {
    //     for (int j = sum[i].size()-1;j>=0; j--)
    //     {
    //         cout << sum[i][j];
    //     }
    //     cout << endl;
    // }
    acarreo=0;
    for (int i = 0; i < mayor; i++)
    {
        // cout<<"funciona";
        int suma = acarreo;
        // cout<<sum.size()<<endl;
        for (int j = 0; j < num1.size(); j++)
        {
            // cout<<i<<" "<<j<<" -"<<sum[j][i]<<endl;
            suma += sum[j][i];
            // system("pause");
        }
        cad += ((suma % 10) + '0');
        acarreo = suma / 10;
    }
    while (acarreo > 0)
    {
        cad += (acarreo % 10) + '0';
        acarreo /= 10;
    }
    // cout<<cad<<endl<<"______"<<endl;
    reverse(cad.begin(), cad.end());
    return cad;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (gets(string1))
    {
        gets(string2);
        num1 = num2 = "";
        for (int i = 0; i < strlen(string1); i++)
        {
            num1 += string1[i];
        }
        for (int i = 0; i < strlen(string2); i++)
        {
            num2 += string2[i];
        }
        // cout << "--" << endl;
        // cout << num1 << endl
        //      << num2 << endl;
        // cin >> num1 >> num2;
        if (num1 == "0" || num2 == "0")
        {
            cout << "0" << endl;
            continue;
            ;
        }
        if(num1.size()<num2.size()){
            swap(num1,num2);
        }
        cout << mul() << endl;
    }

    return 0;
}