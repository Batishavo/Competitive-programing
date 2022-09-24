#include <bits/stdc++.h>

using namespace std;

const int limit = 310;

int n,
    t,
    arr[limit],
    menor;

int sum(int a,int b,int c){

    int num1 = abs(a-b)+abs(a-c),
        num2 = abs(b-a)+abs(b-c),
        num3 = abs(c-b)+abs(c-a);

    return min(num1,min(num2,num3));
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        menor = sum(arr[2],arr[1],arr[0]);

        for (int i = 3; i < n; i++)
        {
            int aux = sum(arr[i],arr[i-1],arr[i-2]);
            menor = min(menor, aux);
        }
        printf("%d\n", menor);
    }

    return 0;
}