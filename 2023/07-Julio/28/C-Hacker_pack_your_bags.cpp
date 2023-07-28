#include <bits/stdc++.h>

using namespace std;

const int limit = 2e5 + 10;
const long long max_value = 10e12;

struct vouncher
{


    int l;
    int r;
    int duration;

    long long cost;

    vouncher()
    {
        //cout<<"HOla";
        this->r = 0;
        this->l = 0;
        this->duration = 0;
        this->cost = 0;
    }

    vouncher(int l, int r, int duration, long long cost)
    {
        this->l = l;
        this->r = r;
        this->duration = duration;
        this->cost = cost;
    }
};

bool oreder_voucher(vouncher a, vouncher b)
{

    if (a.l == b.l)
    {

        if (a.duration == b.duration)
        {

            a.cost < b.cost;
        }

        a.duration < b.duration;
    }
    return a.l < b.l;
}

long long bynary_search(int ini, int fin, vouncher vouchers[], int k)
{

    int pos = ini - 1;
    int n = fin+1;

    while (ini < fin)
    {

        int mid = ini +(fin - ini)/2;

        if (
            vouchers[mid].l <= vouchers[pos].r
        )
        {
            ini=mid+1;
        }
        else {
            if(vouchers[mid].duration + vouchers[pos].duration == k){
                ini = mid +1;
            }
            else{
                fin = mid;
            }
        }
    }
    //cout<<fin<<" "<<ini<<endl;
    if (
        vouchers[fin].l>vouchers[pos].r
        && vouchers[fin].duration + vouchers[pos].duration == k
        && fin < n
    )
    {
        return vouchers[pos].cost + vouchers[fin].cost;
    }
    return max_value;
}

int main()
{
    //cout<<"HOLllllllllll";

    int n;
    int k;

    long long answer = max_value;

    vouncher vouchers[limit];

    cin>>n>>k;

    for (int i = 0; i < n; i++)
    {

        int l;
        int r;
        long long cost;

        cin >> l >> r >> cost;

        vouchers[i] = {l, r, r - l + 1, cost};
    }

    sort(vouchers, vouchers + n, oreder_voucher);

    for (int i = 0; i < n; i++)
    {

        if (vouchers[i].duration < k)
        {
            long long actual_value = bynary_search(i + 1, n - 1, vouchers, k);

            answer = min(actual_value, answer);
        }
    }

    if (answer == max_value)
    {
        cout << "-1";
    }
    else
    {
        cout << answer;
    }
    cout << endl;

    return 0;
}