#include<bits/stdc++.h>

using namespace std;

int main(){

	int q;

	scanf("%d",&q);

	while(q--){

		int n;
		scanf("%d",&n);

		int x = (n + 3) / 4;

        for (int i = 0; i < n - x; ++i) {
            cout << 9;
        }
        for (int i = 0; i < x; ++i) {
            cout << 8;
        }
        printf("\n");
	}
	return 0;
}
