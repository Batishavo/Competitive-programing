#include <bits/stdc++.h>

using namespace std;
int t;
string cad;
int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> cad;
        if ((cad[0] == 'a' && cad[1] == 'a') ||
            (cad[0] == 'b' && cad[1] == 'b') ||
            (cad[0] == 'b' && cad[1] == 'a'))
        {
            // cout<<"--";
            cout << cad[0] << " " << cad[1] << " " << cad.substr(2)<< endl;
        }
        else if((cad[0] == 'a' && cad[1] == 'b')){
            bool flag = 0;
            int cont=0;
            for(int i=1; i<cad.size(); i++){
                if(cad[i] == 'a'){
                    // cout<<"X"<<endl;
                    cout<<cad[0]<<" "<<cad.substr(1,cont)<<" "<<cad.substr(i)<<endl;
                    //cout<<cont<<endl;
                    flag=1;
                    break;
                }
                cont++;
            }
            if(!flag){
                // cout<<"Y"<<endl;
                cout<<cad.substr(0,cad.size()-2)<<" "<<cad[cad.size()-2] <<" "<<cad[cad.size()-1]<<endl;
            }
        }
        else
        {
            cout << ":(" << endl;
        }
    }

    return 0;
}