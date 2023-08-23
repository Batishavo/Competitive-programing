#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int segment_tre[limit * 4];
long long arr[limit];

void build(int node, int start, int fin)
{

    if (start == fin)
    {
        if (arr[start] >= 1)
        {
            segment_tre[node] = 1;
        }
        else if (arr[start] <= 1)
        {
            segment_tre[node] = -1;
        }
        else
        {
            segment_tre[node] = 0;
        }
        return;
    }

    int mid = (start + fin) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, fin);

    segment_tre[node] = segment_tre[2 * node] * segment_tre[2 * node + 1];
}

int query(int node, int start, int fin, int l, int r)
{

    // cout<<"entra"<<endl;

    if (r < start || l > fin)
    {
        return 1;
    }
    if (l <= start && r >= fin)
    {
        return segment_tre[node];
    }

    int mid = (start + fin) / 2;

    int left_sum = query(2 * node, start, mid, l, r);
    int right_sum = query(2 * node + 1, mid + 1, fin, l, r);

    return left_sum * right_sum;
}

void update(int node, int start, int fin, int idx, int val)
{

    // cout<<"entra"<<endl;

    if (start == fin)
    {
        arr[idx-1] += val;
        if (arr[idx-1] >= 1)
        {
            segment_tre[node] = 1;
        }
        else if (arr[idx-1] <= -1)
        {
            segment_tre[node] = -1;
        }
        else
        {
            segment_tre[node] = 0;
        }
        return;
    }

    int mid = (start + fin) / 2;
    if (idx-1 <= mid)
    {
        update(2 * node, start, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, fin, idx, val);
    }

    segment_tre[node] = segment_tre[2 * node] * segment_tre[2 * node + 1];
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int n;
    int q;

    char type;

    while (cin >> n >> q)
    {

        memset(segment_tre, 0, sizeof(segment_tre));

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        build(1, 0, n - 1);
        // for (int i = 0; i < n * 4; i++)
        // {
        //     cout << segment_tre[i] << " ";
        // }
        //cout << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> type;
            // cout<<type<<endl;
            if (type == 'C')
            {
                int idx;
                int val;

                cin >> idx >> val;
                
                update(1, 0, n - 1, idx, val);
                // for (int j = 0; j < n * 4; j++)
                // {
                //     cout << segment_tre[j] << " ";
                // }
                // cout << endl;
            }

            else
            {
                int l;
                int r;

                cin >> l >> r;

                int num = query(1, 0, n , l -1, r-1 );
                printf("%d ", num);
                //  int num = 0;
                /*switch (num)
                {
                case 1:
                    cout << "+";
                    break;
                case -1:
                    cout << "-";
                    break;
                default:
                    cout << "0";
                    break;
                }*/
            }
        }
        cout << endl;
    }
    
    return 0;
}

//prueba de git