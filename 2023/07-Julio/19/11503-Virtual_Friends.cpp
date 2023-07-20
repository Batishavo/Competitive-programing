#include <bits/stdc++.h>

using namespace std;

const int limit = 10e6 + 10;

long long values[limit];
int parent[limit];

long long union_nodes(int first_node, int second_node)
{
    values[first_node] += values[second_node];
    parent[second_node] = first_node;
    return values[first_node];
}

int find_parent(int node)
{

    if (parent[node] != node)
    {
        return find_parent(parent[node]);
    }
    return node;
}

int total_friends(int first_node, int secon_node)
{

    first_node = find_parent(first_node);
    secon_node = find_parent(secon_node);

    if (first_node != secon_node)
    {
        return union_nodes(first_node, secon_node);
    }
    return values[first_node];
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int test;
    int vertices;
    int actual_node=0;

    string person_1;
    string person_2;

    map<string, int> nodes;

    cin >> test;

    while (test--)
    {

        cin >> vertices;

        for (int i = 0; i < vertices; i++)
        {
            cin >> person_1 >> person_2;

            if (nodes[person_1] == 0)
            {
                nodes[person_1] = ++actual_node;
                values[actual_node] = 1;
                parent[actual_node] = actual_node;
            }
            if (nodes[person_2] == 0)
            {
                nodes[person_2] = ++actual_node;
                values[actual_node] = 1;
                parent[actual_node] = actual_node;
            }

            cout << total_friends(nodes[person_1], nodes[person_2]) << endl;
        }

        for (int i = 0; i <= actual_node; i++)
        {
            values[i] = 0;
            parent[i] = 0;
        }
        actual_node=0;
        nodes.clear();
    }

    return 0;
}