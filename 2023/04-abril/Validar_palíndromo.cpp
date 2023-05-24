#include <bits/stdc++.h>

using namespace std;

bool flag = false;
string cad;

bool palindromo(string cad)
{
    int left = 0,
        right = cad.size() - 1;

    while (left < right)
    {
        if (cad[left] != cad[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{

    cin >> cad;

    flag = palindromo(cad);

    for(int i = 0; i < cad.size(); i++){
        if(flag){
            break;
        }
        string cad_left=cad.substr(0,i),
            cad_right=cad.substr(i+1, cad.size()-i-1);
        //cout<<cad_left+cad_right<<endl;
        flag=palindromo(cad_left+cad_right);

    }

    cout<<flag<<endl;

    return 0;
}