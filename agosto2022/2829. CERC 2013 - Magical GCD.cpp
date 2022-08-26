#include<bits/stdc++.h>

using namespace std;

int n,t;

long long mayor;

vector<long long>nums;

long long gcd(long long num1,long long num2){
	long long menor=(num1<num2)?num1:num2;
	long long mayor=(num1>num2)?num1:num2;
	while(mayor%menor!=0){
		long long temp=menor;
		menor=mayor%menor;
		mayor=temp;
	}
	return menor;
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            long long aux;
            scanf("%lld",&aux);
            nums.push_back(aux);
        }
        mayor=nums[nums.size()-1];
        //printf("%lld %d\n",mayor,n);
        long long aux_gcd=mayor;
        for(int i=nums.size()-2;i>=0;i--){

            aux_gcd=gcd(nums[i], aux_gcd);

            long long aux=aux_gcd*(n-i);

            mayor=max(aux,mayor);

           // printf("mayor: %lld aux: %lld gcd: %lld long: %d\n",mayor,aux,aux_gcd,n-i);

        }

        printf("%lld\n",mayor);
        nums.clear();

    }


    return 0;
}
