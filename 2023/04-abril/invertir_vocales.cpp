#include <bits/stdc++.h>

using namespace std;

string cad;

bool is_vocal(char c)
{

    c = tolower(c);

    return c == 'a' ||
           c == 'e' ||
           c == 'i' ||
           c == 'o' ||
           c == 'u' ||
           c == 'y';
}

void mover_vocales()
{

    int left = 0,
        right = cad.length() - 1;

    while (left < right)
    {
        if(!is_vocal(cad[left])){
            left++;
        }
        if(!is_vocal(cad[right])){
            right--;
        }
        if(is_vocal(cad[left]) && is_vocal(cad[right])){
            swap(cad[left], cad[right]);
            left++;
            right--;
        }
    }
}

int main()
{

    cin >> cad;
    mover_vocales();
    cout << cad << endl;

    return 0;
}