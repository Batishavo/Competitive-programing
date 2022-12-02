#include<bits/stdc++.h>
using namespace std;
void mueve ( int n , char x , char y , char z) {
    if ( n==1){
        printf ( "Mueve de %c a %c . %d %d %d %d\n" , x , y) ;
    }
    else{
        mueve ( n-1, x , z , y);
        printf ( "Mueve de %c a %c . %d %d %d %d\n" , x , y) ;
        mueve ( n-1, z , y , x ,c,b,n-1);
    }
}
 void hanoi ( int n ) {
    mueve ( n , 'X' , 'Z' , 'Y') ;
 }
 int main(){

    hanoi(3);
    return 0;
 }
