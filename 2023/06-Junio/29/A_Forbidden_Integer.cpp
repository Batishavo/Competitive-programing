#include <bits/stdc++.h>

using namespace std;

int t, x, k, n, cont;

queue<int> my_queue;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cont = 0;
        cin >> n >> k >> x;

        if ((x == 1 && n == 1) || (x == 1 && k == 1 && n == 2) || (x == 1 && k == 1 && n == 3))
        {
            cout << "NO" << endl;
        }
        else
        {
            if (x != 1)
            {
                if (k == x)
                {
                    k--;
                }
                while (n >= k)
                {
                    my_queue.push(k);
                    n -= k;
                    cont++;
                }
                while (n > 0)
                {
                    my_queue.push(1);
                    n--;
                    cont++;
                }
            }
            else if (k >= 3)
            {
                if (n % 2 != 0)
                {
                    my_queue.push(3);
                    n -= 3;
                    cont++;
                }
                while (n > 0)
                {
                    my_queue.push(2);
                    cont++;
                    n -= 2;
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        if (cont != 0)
        {
            cout << "YES" << endl;
            cout << cont << endl;
            while (!my_queue.empty())
            {
                cout << my_queue.front() << " ";
                my_queue.pop();
            }
            cout << endl;
        }
    }

    return 0;
}