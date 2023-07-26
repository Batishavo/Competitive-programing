#include<bits/stdc++.h>

using namespace std;

const int limit = 1100;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int m;
    int front_cluster[limit];
    int rear_cluster[limit];

    vector<double>drive_ratios;

    double answer;

    while(cin>>n){
        
        answer = 0.0;
        drive_ratios.clear();

        if(n==0){
            break;
        }
        cin>>m;

        for(int i=0;i<n;i++){
            cin>>front_cluster[i];
        }
        for(int i=0;i<m;i++){
            cin>>rear_cluster[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                double spread_rounded = ((double)rear_cluster[j] / (double)front_cluster[i]);
                drive_ratios.push_back(spread_rounded);
            }
        }

        sort(drive_ratios.begin(),drive_ratios.end());

        for(int i=0;i<drive_ratios.size()-1;i++){
            double actual_ratio = drive_ratios[i+1]/drive_ratios[i];
            answer = max(answer,actual_ratio);
        }

        printf("%.2lf\n", answer);

    }

    return 0;
}