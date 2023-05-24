#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int n,
    arr[limit];

bool odd,
    even;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i]%2==0){
            even = true;
        }
        else{
            odd = true;
        }
    }

    if(odd && even){
        sort(arr,arr+n);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}