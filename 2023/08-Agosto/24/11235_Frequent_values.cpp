#include <bits/stdc++.h>

using namespace std;

const int sum = 100000;

map<int, pair<int, int>> frequency;

map<int, pair<int, int>>:: iterator it;

int arr[sum + 10];
int segment_tree[4*sum];

int calcula_maximo(int num1,int num2){

}

void build(int node,int start,int fin){
    if(start == fin){
        segment_tree[node] = arr[start];
        return;
    }

    int mid = (start+fin)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,fin);

    segment_tree[node] = calcula_maximo(segment_tree[2*node],segment_tree[2*node+1]);
    
}

int query(int node,int start,int fin,int l,int r){

}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int n;
    int q;

    int l;
    int r;

    frequency.clear();

    while (cin >> n)
    {

        if (n == 0)
        {
            break;
        }

        cin >> q;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] < 0)
            {
                arr[i] *= -1;
                arr[i] += sum;
            }
            
            it = frequency.find(arr[i]);

            if (it==frequency.end())
            {
                frequency[arr[i]] = {i, i};
            }
            else
            {
                frequency[arr[i]].second++;
            }
        }

        while(q--){
            cin>>l>>r;
            cout<<query(1,0,n-1,l-1,r-1)<<endl;
        }
        /*for (auto x : frequency)
        {
            cout << x.first << " " << x.second.first << " " << x.second.second << finl;
        }*/
    }

    return 0;
}