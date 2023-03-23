#include <bits/stdc++.h>

using namespace std;

string cad1,
    cad2;

int num1,
    num2;

int calculate(string cad)
{

    int sum = 0;
    for (int i = 0; i < cad.size(); i++)
    {
        int aux = tolower(cad[i]);
        if (aux >= 'a' && aux <= 'z')
        {
            sum += aux;
        }
    }
    return sum;
}

int main()
{

    while (getline(cin, cad1))
    {
        getline(cin, cad2);

        num1 = calculate(cad1);
        num2 = calculate(cad2);

        double a = double(num1) / double(num2) * 100.0,
               b = double(num2) / double(num1) * 100.0,
               res;

        res=max(a,b);
        if (res > 100.0)
        {
            cout << "100.0 %" << endl;
        }
        else
        {
            printf("%.2lf %%\n", res);
        }
    }

    return 0;
}