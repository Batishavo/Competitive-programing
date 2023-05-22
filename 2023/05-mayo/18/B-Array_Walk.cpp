#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int ans = 0;
        int s = 0;
        int mx = 0;
        for (int i = 0; i <= k; i++) {
            if (i < n - 1) {
                mx = max(mx, a[i] + a[i + 1]);
            }
            s += a[i];
            if (i % 2 == k % 2) {
                int tmp = (k - i) / 2;
                if (tmp <= z) {
                    ans = max(ans, s + mx * tmp);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}