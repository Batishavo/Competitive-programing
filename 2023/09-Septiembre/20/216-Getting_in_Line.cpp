#include <bits/stdc++.h>

using namespace std;

double distant_computer(pair<int, int> computer1, pair<int, int> computer2)
{
    //cout<<"entra"<<endl;
    int dx = computer1.first - computer2.first;
    int dy = computer1.second - computer2.second;

    return sqrt((dx * dx) + (dy * dy))+16;
}

double route_long(
    vector<int> &route,
    vector<pair<int, int>> &computers_pos)
{

    double answer = 0.0;
    int route_size = route.size();

    for (int i = 0; i < route_size-1; i++)
    {
        int actual_pc = route[i];
        int next_pc = route[i+1];
        //cout<<actual_pc<<" "<<next_pc<<endl;
        answer += distant_computer(computers_pos[actual_pc], computers_pos[next_pc]);
        
    }
    return answer;
}

void best_route(int n, vector<pair<int, int>> &computers_pos)
{
    vector<int> route(n);
    //asign susive values
    iota(route.begin(),route.end(),0);

    double best_size = numeric_limits<double>::max();
    vector<int> best_route;
    int cont = 0;
    do{
        cont ++;
        //cout<<"llama a la funcio"<<endl;
        double actual_logitud = route_long(route,computers_pos);
        if(actual_logitud<best_size){
            best_size = actual_logitud;
            best_route = route;
        }

    }while(next_permutation(route.begin() , route.end()));

    //cout<<cont<<endl;

    int ant_pos = best_route[0];
    for(int i=1;i<n;i++){
        int pos = best_route[i];
        //cout<<best_route[i-1]<<" "<<pos<<endl;
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
            computers_pos[ant_pos].first,
            computers_pos[ant_pos].second,
            computers_pos[pos].first,
            computers_pos[pos].second,
            distant_computer(computers_pos[ant_pos],computers_pos[pos])
        );
        ant_pos=pos;
    }

    printf("Number of feet of cable required is %.2lf.\n",best_size);

}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int num = 1;
    vector<pair<int, int>> compueters_pos;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        compueters_pos.clear();
        for (int i = 0; i < n; i++)
        {

            pair<int, int> tmp_computers_pos;

            cin >> tmp_computers_pos.first 
                >> tmp_computers_pos.second;
            
            compueters_pos.push_back(tmp_computers_pos);
        }

        cout << "**********************************************************" << endl;
        cout << "Network #" << num++ << endl;
        best_route(n, compueters_pos);
    }

    return 0;
}
