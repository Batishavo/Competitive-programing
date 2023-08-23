#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int arr[limit];
int segment_tree[limit * 4];

int num_sign(int num)
{
    if (num >= 1)
    {
        return 1;
    }
    else if (num <= -1)
    {
        return -1;
    }

    return 0;
}

void build(int node, int start, int fin)
{
    if (start == fin)
    {
        segment_tree[node] = num_sign(arr[start]);
        return;
    }
    int mid = (start + fin) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, fin);

    segment_tree[node] = segment_tree[2 * node] * segment_tree[2 * node + 1];
}

void update(int node, int start, int fin, int index, int val)
{
    cout<<node<<endl;
    if (start == fin)
    {
        arr[index] = val;
        segment_tree[node] = num_sign(val);
        //cout << node << "**" << segment_tree[node] << " " << val << endl;
        return;
    }
    int mid = (start + fin) / 2;
    if (index <= mid)
    {
        update(node * 2, start, mid, index, val);
    }
    else
    {
        update(node * 2 + 1, mid + 1, fin, index, val);
    }
    segment_tree[node] = segment_tree[2 * node] * segment_tree[2 * node + 1];
    //cout << node << " " << segment_tree[node] << endl;
}

char sign(int num)
{
    if (num >= 1)
    {
        return '+';
    }
    else if (num <= -1)
    {
        return '-';
    }

    return '0';
}

int query(int node, int start, int fin, int l, int r)
{
    if (r < start || l > start)
    {
        return 0;
    }
    if (l <= start && r >= fin)
    {
        return segment_tree[node];
    }
    int mid = (start + fin) / 2;
    return query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, fin, l, r);
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    // cout<<"nuevo"<<endl;

    int n;
    int m;
    int left;
    int right;

    char type;

    while (cin >> n >> m)
    {

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        memset(segment_tree, 0, sizeof(segment_tree));

        build(1, 0, n - 1);

        for (int i = 0; i < n * 4; i++)
        {
            cout << segment_tree[i] << " ";
        }
        cout << endl;

        while (m--)
        {
            cin >> type >> left >> right;
            if (type == 'C')
            {
                update(1, 0, n-1, left-1 , right);
                for (int i = 0; i < n * 4; i++)
                {
                    cout << segment_tree[i] << " ";
                }
                cout << endl;
            }
            else
            {
                //cout<<sign(query(1,0,n-1,left-1,right-1));
            }
        }
        cout << endl;
    }

    return 0;
}