#include <bits/stdc++.h>

using namespace std;

string cad1,
    cad2;

int num1,
    num2;

int sum_num(int num)
{
    while (num > 9)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int calculate(string cad)
{

    int sum = 0;
    for (int i = 0; i < cad.size(); i++)
    {
        int aux = tolower(cad[i]);
        if (aux >= 'a' && aux <= 'z')
        {
            // cout << aux << " " << aux - 'a' + 1 << endl;
            sum += aux - 'a' + 1;
        }
    }
    sum = sum_num(sum);
    return sum;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (getline(cin, cad1))
    {
        getline(cin, cad2);

        num1 = calculate(cad1);
        num2 = calculate(cad2);

        double a = double(num1) / double(num2) * 100.0,
               b = double(num2) / double(num1) * 100.0,
               res;

        res = min(a, b);
        // cout << a << " " << b << endl;
        cout << fixed << setprecision(2) << res <<" %"<< endl;
    }

    return 0;
}