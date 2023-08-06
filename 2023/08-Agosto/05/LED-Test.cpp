#include <bits/stdc++.h>

using namespace std;

int n;

string cads[15];

map<int, string> led_value;

bool can_be_equals(string cad_led, string cad_tmp)
{

    for (int i = 0; i < 7; i++)
    {
        if (cad_led[i] != cad_tmp[i] && cad_tmp[i] == 'Y')
        {
            return false;
        }
    }
    return true;
}

void init()
{

    led_value[0] = "YYYYYYN";
    led_value[1] = "NYYNNNN";
    led_value[2] = "YYNYYNY";
    led_value[3] = "YYYYNNY";
    led_value[4] = "NYYNNYY";
    led_value[5] = "YNYYNYY";
    led_value[6] = "YNYYYYY";
    led_value[7] = "YYYNNNN";
    led_value[8] = "YYYYYYY";
    led_value[9] = "YYYYNYY";
}

bool comp()
{

    int num = 9;

    //cout << n<<endl;;

    for (int k = 0; k <= 9 - n; k++)
    {

        int pos = 0;

        bool flag = true;

        for (int i = num; i > num - n; i--)
        {

            // cout << num << endl
            //      << "*********\n";

            if (!can_be_equals(led_value[i], cads[pos++]))
            {
                flag = false;
                break;
            }
        }

        num--;

        if (flag)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    init();

    while (cin >> n)
    {

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> cads[i];
        }

        if (n == 1)
        {
            cout << "MATCH\n";
        }
        else
        {

            if (comp())
            {
                cout << "MATCH\n";
            }
            else
            {
                cout << "MISMATCH\n";
            }
        }
    }

    return 0;
}