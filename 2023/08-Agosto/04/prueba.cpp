// Se omiten includes y defines
#include <bits/stdc++.h>

using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unsigned long long ll;
 
int n, m;
vii dominoes;
ii init, fin;
int izq, der, taken;
bool done;
 
void solve(int lastMatched, int actual) {
    if (actual == n) {
        for (int i=0 ; i<m && !done ; i++) {
            if ((taken & (1 << i)) == 0) {
                if (lastMatched == dominoes[i].first && dominoes[i].second == fin.first)
                    done = true;
                if (lastMatched == dominoes[i].second && dominoes[i].first == fin.first)
                    done = true;
            }
        }
    }
 
    for (int i=0 ; i<m && !done ; i++) {
        if ( (taken & (1 << i)) == 0) {
            if (lastMatched == dominoes[i].first) {
                taken |= (1 << i);
                solve(dominoes[i].second, actual+1);
                taken &= ~(1 << i);
            }
 
            if (lastMatched == dominoes[i].second) {
                taken |= (1 << i);
                solve(dominoes[i].first, actual+1);
                taken &= ~(1 << i);
            }
        }
    }
}
 
int main() {
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    while (scanf("%d\n", &n), n) {
        done = false;
        dominoes.clear();
        scanf("%d\n", &m);
         
        scanf("%d %d\n", &izq, &der);
        init.first = izq;
        init.second = der;
 
        scanf("%d %d\n", &izq, &der);
        fin.first = izq;
        fin.second = der;
 
        for(int i=0;i< m;i++) {
            scanf("%d %d\n", &izq, &der);
            dominoes.push_back(ii(izq, der));
        }
 
        solve(init.second, 1);
 
        if (done) printf("YES\n");
        else printf("NO\n");
    }
}