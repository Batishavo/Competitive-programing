#include<bits/stdc++.h>

using namespace std;

const int lim=2e5+10;

int arr[lim];

int main(){

	int q;

	scanf("%d",&q);

	while(q--){

		int n;
		scanf("%d",&n);

		int p1=1,
            p2=n,
            a=arr[p1],
            b=arr[p2],
            res=0;

		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}

        while(p2!=0){

            if(arr[p2-1]>=arr[p2]){

                p2--;

            }
            else{
                break;
            }

        }
        while(p1<p2){
            if(arr[p1+1]<arr[p1]){

                res=p1;
            }
            if(p1+1<p2-1){

                p1++;

            }
            else{
                break;
            }


        }
        //printf("**%d\n",p2);
        printf("%d\n",res);

	}
	return 0;
}
