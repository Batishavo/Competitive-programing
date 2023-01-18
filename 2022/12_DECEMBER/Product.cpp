#include <bits/stdc++.h>

using namespace std;

const int fin = 30;

int mat[510][260];

string num1, num2;

void suma(int litle,int big)
{
    // cout<<"--------"<<endl;
    // for(int i=0;i<fin+1;i++){
    //     for(int j=0;j<fin+1;j++){
    //         cout<<mat[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<"--------"<<endl;
    int sum = 0,
        acumulado = 0;
    string cad = "";
    for (int i = fin; i > fin -big-litle+1 ; i--)
    {
        sum=acumulado;
        //printf("--%d %d\n",i,mat[0][i]);
        for (int j = 0; j < litle; j++)
        {
            //printf("j: %d i: %d ",j,i);
            // cout<<"m: "<<mat[j][i]<<endl;
            sum += mat[j][i];
        }
        // cout<<"------"<<endl;
        // cout<<sum<<endl;
        cad+=(sum%10)+'0';
        acumulado=sum/10;
    }
    cout<<acumulado<<endl;
    while(acumulado>0){
        cad+=(acumulado%10)+'0';
        acumulado/=10;
    }
    reverse(cad.begin(),cad.end());
    cout<<cad<<endl;
}

void llenado(int litle, int big, string l, string b)
{

    int acumulado = 0,
        r1 = 0,
        r2 = 0;

    for (int i = litle - 1; i >= 0; i--)
    {
        r1++;
        r2 = 0;
        for (int j = big - 1; j >= 0; j--)
        {
            r2++;
            int sum = ((l[i] - '0') * (b[j] - '0') + acumulado);
            mat[r1 - 1][fin - r1 - r2 + 2] = sum % 10;
            acumulado = sum / 10;
            // printf("acumulado: %d\n",acumulado);
            // printf("sum: %d \n",sum);
        }
        mat[r1 - 1][fin - r1 + 1 - big] = acumulado;
        // cout<<"**"<<endl;
    }
    suma(litle, big);
}

void llenarMatris(int lonn1, int lonn2)
{
    if (lonn1 < lonn2)
    {
        llenado(lonn1, lonn2, num1, num2);
    }
    else
    {
        llenado(lonn2, lonn1, num2, num1);
    }
}

void clean(){

    for(int i = 0; i <fin;i++){
        for(int j = 0; j < fin; j++){
            mat[i][j] = 0;
        }
    }

};

int main()
{

    while (true)
    {
        cin >> num1 >> num2;
        llenarMatris(num1.size(), num2.size());
        // cout<<suma();
        clean();
    }

    return 0;
}