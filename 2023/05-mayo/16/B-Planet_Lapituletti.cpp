#include <bits/stdc++.h>

using namespace std;

struct my_time
{
    int h,
        m;

    my_time(int h, int m)
    {
        this->h = h;
        this->m = m;
    }
    my_time()
    {
        h = 0;
        m = 0;
    }
};

int t,
    h,
    m;

string clock_time;

int reverse_time(int num)
{
    if (num == 0)
    {
        return 0;
    }
    string cad = "";
    while (num > 0)
    {
        if (
            num % 10 == 3 ||
            num % 10 == 4 ||
            num % 10 == 6 ||
            num % 10 == 7 ||
            num % 10 == 9)
        {
            return -1;
        }
        else if (num % 10 == 2)
        {
            cad += '5';
        }
        else if (num % 10 == 5)
        {
            cad += '2';
        }
        else
        {
            cad += (num % 10) + '0';
        }
        num /= 10;
    }
    if (cad.length() == 1)
    {
        cad += '0';
    }
    return stoi(cad);
}

bool reflected_valid(my_time actual)
{
    // cout<<"Z"<<endl;
    int num1 = reverse_time(actual.m),
        num2 = reverse_time(actual.h);

    if (num1 == -1 || num2 == -1)
    {
        return false;
    }
    //cout<<num1<<" "<<num2<<endl;

    return num1 < h && num2 < m;
}

my_time next_time(my_time actual)
{

    // cout<<actual.h<<" "<<actual.m<<endl;
    if (actual.m + 1 < m)
    {

        actual.m += 1;
    }
    else
    {
        actual.m = 0;
        if (actual.h + 1 < h)
        {
            actual.h += 1;
        }
        else
        {
            actual.h = 0;
        }
    }
    return actual;
}

my_time make_my_time()
{

    /*cout<<clock_time.substr(0,2)<<" "
        <<clock_time.substr(3,2)
        <<endl;*/

    int h = stoi(clock_time.substr(0, 2)),
        m = stoi(clock_time.substr(3, 2));

    my_time result = {h, m};

    return result;
}

string make_string(my_time actual)
{
    string h = to_string(actual.h),
           m = to_string(actual.m);
    if (h.length() == 1)
    {
        h = "0" + h;
    }
    if (m.length() == 1)
    {
        m = "0" + m;
    }
    return h + ":" + m;
}

string reflected_time()
{

    my_time actual_time = make_my_time();

    while (!reflected_valid(actual_time))
    {
        actual_time = next_time(actual_time);
        // cout<<"X"<<endl;
    }

    return make_string(actual_time);
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        cin >> h >> m >> clock_time;

        cout << reflected_time() << endl;
    }

    return 0;
}