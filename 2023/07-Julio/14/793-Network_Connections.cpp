#include <bits/stdc++.h>

using namespace std;

int parent[2000];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

bool is_united(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    return a == b;
}

void clean(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int test, correct, wrong, n, v1, v2;

    char type;

    bool flag = true;

    string str
        ,trash;

    cin >> test;

    while (test--)
    {

        clean(n);
        correct = 0;
        wrong = 0;

        if (!flag)
        {
            cout << endl;
        }
        else
        {
            flag = false;
        }

        cin >> n;
        getline(cin,trash);

        while (true)
        {
            if(!getline(cin,str) || str.empty()) break;

            sscanf(str.c_str(), "%c %d %d", &type, &v1, &v2);

            // cin >> type >> v1 >> v2;

            if (parent[v1] == 0)
            {
                make_set(v1);
            }

            if (parent[v2] == 0)
            {
                make_set(v2);
            }

            if (type == 'c')
            {
                union_sets(v1, v2);
            }
            else
            {
                if (is_united(v1, v2))
                {
                    correct++;
                }
                else
                {
                    wrong++;
                }
            }
        }

        cout << correct << "," << wrong << endl;
    }

    return 0;
}