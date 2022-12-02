#include<bits/stdc++.h>

using namespace std;

int n,
    test,
    b,
    sg,
    sb,
    aux;

vector <int> gren,
             blue;

queue  <int> gren_aux,
             blue_aux;

int main(){

    bool flag=0;

    scanf("%d",&test);

    while(test--){

        if(flag==1){
            printf("\n");
        }
        else{
            flag=1;
        }

        scanf("%d %d %d",&b,&sg,&sb);

        while(sg--){

            scanf("%d",&aux);

            gren.push_back(aux);

        }
        while(sb--){

            scanf("%d",&aux);

            blue.push_back(aux);

        }

        make_heap(gren.begin(), gren.end());
        make_heap(blue.begin(), blue.end());

        while(gren.size()!=0 && blue.size()!=0){

            for(int i=0;i<b;i++){

                if(gren.size()==0 || blue.size()==0){
                    break;
                }

                gren_aux.push(gren.front());
                blue_aux.push(blue.front());

                pop_heap(gren.begin(), gren.end());
                gren.pop_back();

                pop_heap(blue.begin(), blue.end());
                blue.pop_back();

            }

            while(blue_aux.size()>0 && gren_aux.size()>0){

                if(blue_aux.front()>gren_aux.front()){

                    aux=blue_aux.front()-gren_aux.front();

                    blue.push_back(aux);
                    push_heap(blue.begin(), blue.end());


                }
                else if(blue_aux.front()<gren_aux.front()){

                    aux=gren_aux.front()-blue_aux.front();

                    gren.push_back(aux);
                    push_heap(gren.begin(), gren.end());

                }

                blue_aux.pop();
                gren_aux.pop();
            }

        }

        if(gren.size()==0 && blue.size()==0){

            printf("green and blue died\n");

        }
        else if( blue.size()!=0){

            printf("blue wins\n");

            sort_heap(blue.begin(),blue.end());
            reverse(blue.begin(),blue.end());

            for(auto x: blue){

                printf("%d\n",x);
            }

        }
        else{

            printf("green wins\n");

            sort_heap(gren.begin(),gren.end());
            reverse(gren.begin(),gren.end());

            for(auto x: gren){

                printf("%d\n",x);
            }

        }

        gren.clear();
        blue.clear();

    }

    return 0;
}
