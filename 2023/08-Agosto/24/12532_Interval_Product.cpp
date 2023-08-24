#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int arr[limit];
char segment_tree[limit];

char sign_type(int num)
{

    if (num > 0)
    {
        return '+';
    }
    else if (num < 0)
    {
        return '-';
    }

    return '0';
}

char mul_sign(char val_1,char val_2){

    if(val_1==val_2 && val_1!='0'){
        return '+';
    }
    else if(val_1!='0' && val_2!='0' && val_1!=val_2){
        return '-';
    }

    return '0';

}

void build(int node, int start, int fin)
{
    if (start == fin)
    {
        segment_tree[node] = sign_type(arr[start]);
        return;
    }
    int mid = (start + fin) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, fin);

    segment_tree[node] = mul_sign(segment_tree[2*node],segment_tree[2*node+1]);  

}

char query(int node,int start,int fin,int l,int r){
    if(r<start || l>fin){
        return '0';
    }
    if(l<=start && r>=fin){
        return segment_tree[node];
    }

    int mid = (start + fin) / 2;

    char left_sign = query(2*node,start,mid,l,r);
    char right_sign = query(2*node+1,mid+1,fin,l,r);

    return mul_sign(left_sign,right_sign);
}

void update(int node,int start,int fin,int index,int val){
    if(start==fin){
        arr[index] = val;
        segment_tree[node] = sign_type(arr[index]);
        return;
    }

    int mid = (start + fin) / 2;

    if(index<=mid){
        update(2*node,start,mid,index,val);
    }
    else{
        update(2*node+1,mid+1,fin,index,val);
    }

    segment_tree[node] = mul_sign(segment_tree[2*node],segment_tree[2*node+1]);
}

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int m;
    int n;

    char type;

    while (cin >> n >> m)
    {

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        build(1, 0, n - 1);

        while (m--)
        {

            cin >> type;

            if (type == 'C')
            {
                int index;
                int val;

                cin >> index >> val;

                update(1,0,n-1,index-1,val);
            }
            else
            {
                int l;
                int r;

                cin >> l >> r;

                char result = query(1, 0, n - 1, l - 1, r - 1);

                cout << result ;
            }

        }
        cout << endl;
    }

    return 0;
}