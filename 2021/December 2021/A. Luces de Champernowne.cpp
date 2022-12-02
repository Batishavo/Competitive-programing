#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;;i++){
        int num=i;
        string cad="";

        if(num==0){
            cad+='0';
        }
        while(num>0){
            cad+=(num%10)+'0';
            num/=10;
        }
        n-=cad.length();
        if(n<=0){
            //reverse(cad.begin(),cad.end());

            cout<<cad<<"  "<<n<<endl;
            n=abs(n);
            //printf("%d",n );
            cout<<cad[n]<<endl;
            switch (cad[n]){
                case '0':
                    printf("Rojo\n");
                break;
                case '1':
                    printf("Naranja\n");
                break;
                case '2':
                    printf("Amarillo\n");
                break;
                case '3':
                    printf("Lima\n");
                break;
                case '4':
                    printf("Cyan\n");
                break;
                case '5':
                    printf("Azul\n");
                break;
                case '6':
                    printf("Indigo\n");
                break;
                case '7':
                    printf("Morado\n");
                break;
                case '8':
                    printf("Rosa\n");
                break;
                case '9':
                    printf("Magenta\n");
                break;
            }
          break;
        }
    }
    return 0;
}
