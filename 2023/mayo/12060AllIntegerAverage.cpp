#include <bits/stdc++.h>

using namespace std;

int n,
    sum,
    aux,
    query;

void print_line(int a, int b)
{
    while (a > 0 || b > 0)
    {
        a /= 10;
        b /= 10;
        cout << "-";
    }
    cout << endl;
}
void spaces(int a, int b)
{
    string cad1 = to_string(a),
           cad2 = to_string(b);
    while (cad1.length() < cad2.length())
    {
        cout << " ";
        cad1 += '1';
    }
}
int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            sum += aux;
        }
        printf("Case %d:\n", ++query);
        if (abs(sum) % n == 0)
        {
            // cout<<sum<<endl;
            if(sum<0){
                cout<<"- ";
            }
            cout << abs(sum / n )<< endl;
        }
        else if (sum / n == 0)
        {
            // cout<<"X"<<endl;
            int num1 = abs(sum % n),
                num2 = n;
            while (__gcd(num1, num2) != 1)
            {
                for (int i = 2;; i++)
                {
                    if (num1 % i == 0 && num2 % i == 0)
                    {
                        num1 /= i;
                        num2 /= i;
                        break;
                    }
                }
            }
            if (sum < 0)
            {
                cout << "  ";
            }
            spaces(num1, num2);
            cout << num1 << endl;
            if (sum < 0)
            {
                cout << "- ";
            }
            print_line(num1, num2);
            if (sum < 0)
            {
                cout << "  ";
            }
            spaces(num2, num1);
            cout << num2 << endl;
        }
        else
        {
            int aux = abs(sum / n),
                num1 = abs(sum % n),
                num2 = n;
            // cout<<"Y"<<endl;
            while (__gcd(num1, num2) != 1)
            {
                for (int i = 2;; i++)
                {
                    if (num1 % i == 0 && num2 % i == 0)
                    {
                        num1 /= i;
                        num2 /= i;
                        break;
                    }
                }
            }
            while (aux > 0)
            {
                cout << " ";
                aux /= 10;
            }
            if (sum < 0)
            {
                cout << "  ";
            }
            spaces(num1, num2);
            cout << num1 << endl;
            if (sum < 0)
            {
                cout << "- ";
            }
            cout << abs(sum / n);
            print_line(num1, num2);
            aux = abs(sum / n);
            while (aux > 0)
            {
                cout << " ";
                aux /= 10;
            }
            if (sum < 0)
            {
                cout << "  ";
            }
            spaces(num2, num1);
            cout << num2 << endl;
        }
        sum = 0;
    }

    return 0;
}