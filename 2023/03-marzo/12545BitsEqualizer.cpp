#include <bits/stdc++.h>

using namespace std;

int t,
    myCase,
    answer;

string cad,
    cad2;

int numOfOnes(string cad)
{
    int nums = 0;
    for (int i = 0; i < cad.size(); i++)
    {
        if (cad[i] == '1')
        {
            nums++;
        }
    }
    return nums;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {

        cin >> cad >> cad2;
        if (numOfOnes(cad) > numOfOnes(cad2))
        {
            answer = -1;
        }
        else
        {
            int ceroOne=0,
                oneCero=0;


            for (int i = 0; i < cad.size(); i++)
            {
                if (cad[i] == '1' && cad2[i] == '0')
                {
                    oneCero++;
                }
                else if (cad[i] == '0' && cad2[i] == '1')
                {
                    ceroOne++;
                }
                else if (cad[i] == '?')
                {
                    answer++;
                }
            }
            if(ceroOne>=oneCero){
                answer+=ceroOne;
            }
            else{
                answer+=ceroOne+(oneCero-ceroOne);
            }
        }

        printf("Case %d: %d\n", ++myCase, answer);
        answer = 0;
    }

    return 0;
}