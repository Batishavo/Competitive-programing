#include<bits/stdc++.h>

using namespace std;

int n;

struct person
{
    string name;

    int day,
        month,
        year;
};

person arr[110];


bool order(person a, person b){

    if(a.year == b.year){

        if(a.month == b.month){

            a.day < a.day;

        }

        return a.month < b.month;

    }

    return a.year < b.year;

}

int main(){

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>arr[i].name
           >>arr[i].day
           >>arr[i].month
           >>arr[i].year;
    }
    
    sort( arr ,arr+n,order);
    
    cout<<arr[n-1].name<<endl
        <<arr[0]  .name<<endl;

    return 0;
}