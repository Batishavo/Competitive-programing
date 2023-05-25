#include <bits/stdc++.h>

using namespace std;

int n,
    num;

string cad;

bool flag = true;

int main()
{

    cin >> n >> cad;

    while (flag)
    {
        bool flag_actual = false;
        int pos=0,
            val=0;


        for (int i = 1; i < cad.size(); i++)
        {
            if (abs(cad[i] - cad[i - 1]) == 1)
            {
                flag_actual = true;
                int tmp = (cad[i] > cad[i - 1]) ? cad[i]:cad[i - 1];

                if(tmp>val){
                    val = tmp;
                    pos=(cad[i] > cad[i - 1]) ? i : i - 1;
                }
                
            }
        }

        num += flag_actual;
        flag = flag_actual;

        cad = cad.substr(0, pos)+cad.substr(pos+1);
    }

    cout << num << endl;

    return 0;
}