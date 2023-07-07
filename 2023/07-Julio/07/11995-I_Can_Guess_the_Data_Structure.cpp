#include<bits/stdc++.h>

using namespace std;

bool is_stack(int n,vector<pair<int,int>>& my_data){
    
    stack<int> my_stack;

    for(int i=0;i<n;i++){
        if(my_data[i].first == 1){
            my_stack.push(my_data[i].second);
        }
        else{
            if(my_stack.empty() || my_stack.top() != my_data[i].second){
                return false;
            }
            else{
                my_stack.pop();
            }
        }
    }

    return true;

}

bool is_queue(int n,vector<pair<int,int>>& my_data){
   
    queue<int> my_queue;

    for(int i=0;i<n;i++){
        if(my_data[i].first == 1){
            my_queue.push(my_data[i].second);
        }
        else{
            if(my_queue.empty() ||  my_queue.front() != my_data[i].second){
                return false;
            }
            else{
                my_queue.pop();
            }
        }
    }

    return true;
}

bool is_priority_queue(int n,vector<pair<int,int>>& my_data){
    priority_queue<int> my_priority_queue;

    for(int i=0;i<n;i++){
        if(my_data[i].first == 1){
            my_priority_queue.push(my_data[i].second);
        }
        else{
            if( my_priority_queue.empty() ||  my_priority_queue.top() != my_data[i].second){
                return false;
            }
            else{
                my_priority_queue.pop();
            }
        }
    }

    return true;

}


int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;

    vector<pair<int,int>> my_data;

    while(cin>>n){

        my_data.clear();
        
        for(int i=0;i<n;i++){
            
            int comand
                ,my_integer;
            
            cin>>comand
               >>my_integer;

            my_data.push_back({comand,my_integer});

        }

        bool flag_stack=is_stack(n,my_data)
            ,flag_queue=is_queue(n,my_data)
            ,flag_priority_queue=is_priority_queue(n,my_data);
        
        if(flag_stack+flag_priority_queue+flag_queue==0){
            cout<<"impossible";
        }
        else if(flag_stack+flag_priority_queue+flag_queue>1){
            cout<<"not sure";
        }
        else if(flag_stack){
            cout<<"stack";
        }
        else if(flag_queue){
            cout<<"queue";
        }
        else{
            cout<<"priority queue";
        }

        cout<<endl;

    }

    return 0;
}
