#include<bits/stdc++.h>

using namespace std;

const int limit= 150;

long long n,
    m,
    test,
    mat1[limit][limit],
    mat2[limit][limit],
    mat3[limit][limit],
    mat4[limit][limit];

long long cont=0;

vector<long long>vect;

int main(){

    scanf("%lld",&test);

    while(test--){

        scanf("%lld %lld",&n,&m);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%lld",&mat1[i][j]);
                mat2[i][m-j-1]=mat1[i][j];
                mat3[n-i-1][j]=mat1[i][j];
                mat4[n-i-1][m-j-1]=mat1[i][j];

            }

        }

        for(int i=0;i<n/2;i++){

            for(int j=0;j<m/2;j++){

                vect.push_back(mat1[i][j]);
                vect.push_back(mat2[i][j]);
                vect.push_back(mat3[i][j]);
                vect.push_back(mat4[i][j]);
             sort(vect.begin(),vect.end());

                cont +=  abs(mat1[i][j]-vect[1])+
                        abs(mat2[i][j]-vect[1])+
                        abs(mat3[i][j]-vect[1])+
                        abs(mat4[i][j]-vect[1]);
                vect.clear();

            }

        }

        if(n%2!=0){

            for(int i=0;i<m/2;i++){


                cont+= abs(mat1[(n/2)][i]-mat1[(n/2)][m-1-i]);

            }

        }
        if(m%2!=0){

            for(int i=0;i<n/2;i++){

                cont+= abs(mat1[i][(m/2)]-mat1[n-1-i][(m/2)]);

            }

        }

        printf("%lld\n",cont);

        cont=0;
        /*printf("\n\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",mat2[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",mat3[i][j]);
            }
            printf("\n");
        }
         printf("\n\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",mat4[i][j]);
            }
            printf("\n");
        }*/
    }

	return 0;
}
