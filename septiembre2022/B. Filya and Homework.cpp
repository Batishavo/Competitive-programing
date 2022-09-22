#include<bits/stdc++.h>
using namespace std;

map<int,bool>memo;
vector<int>diferents_nums;

int n,aux;

int main(){

    scanf("%d",&n);

    while(n--){
        scanf("%d",&aux);
        if(memo[aux]==0){
            memo[aux]=1;
            diferents_nums.push_back(aux);
        }
    }

    int tam=diferents_nums.size();

    if(tam>3){
        printf("NO\n");
    }
    else if(tam==1 || tam==2){
        printf("YES");
    }
    else if(tam==3){
        sort(diferents_nums.begin(),diferents_nums.end());

        int num1=abs(diferents_nums[0]-diferents_nums[1]),
            num2=abs(diferents_nums[1]-diferents_nums[2]);
        if(num1==num2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }

    return 0;
}
