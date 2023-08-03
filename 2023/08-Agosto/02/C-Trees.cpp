#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int binary_search()
{

    // TODO : Make the bianary search algorithm
    return 0;
}

int main()
{

    int n;

    int arr[limit];
    int make_0[limit];

    cin >> n;

    bool is_ood = !(n % 2 == 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n / 2 + is_ood; i++)
    {

        make_0[i] = arr[i] - i + 1;
    }

    int pos = 1;

    for (int i = n; i > n / 2 + is_ood; i--)
    {
        make_0[i] = arr[i] - pos + 1;
    }

    for(int i=0;i<n;i++){
        cout<<make_0[i]<<" ";
    }
    cout<<endl;

    //cout << binary_search() << endl;

    return 0;
}