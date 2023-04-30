#include <bits/stdc++.h>

using namespace std;

map<pair<string, string>, vector<string>> fathers,
    father_child;

int query;

string fater,
    mother,
    child;

void init_faters()
{
    /////////
    pair<string, string> tmp = {"A", "A"};
    vector<string> valor = {"O", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"A", "B"};
    valor = {"O", "AB", "B", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"A", "AB"};
    valor = {"AB", "B", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"A", "O"};
    valor = {"O", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"B", "B"};
    valor = {"O", "B"};
    fathers[tmp] = valor;
    //////
    tmp = {"AB", "B"};
    valor = {"AB", "B", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"B", "O"};
    valor = {"O", "B"};
    fathers[tmp] = valor;
    //////////
    tmp = {"AB", "AB"};
    valor = {"AB", "B", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"AB", "O"};
    valor = {"B", "A"};
    fathers[tmp] = valor;
    //////
    tmp = {"O", "O"};
    valor = {"O"};
    fathers[tmp] = valor;
}

void init_father_child()
{
    /////////
    pair<string, string> tmp = {"A", "A"};
    vector<string> valor = {"O", "AB", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"A", "B"};
    valor = {"AB", "B"};
    father_child[tmp] = valor;
    //////
    tmp = {"B", "A"};
    valor = {"AB", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"A", "AB"};
    valor = {"AB", "B"};
    father_child[tmp] = valor;
    //////
    tmp = {"AB", "A"};
    valor = {"O","AB", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"A", "O"};
    valor = {"O", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"O", "A"};
    valor = {"AB", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"AB", "AB"};
    valor = {"AB", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"B", "B"};
    valor = {"O", "AB", "B", "A"};
    father_child[tmp] = valor;
    /////////////
    tmp = {"AB", "B"};
    valor = {"O", "AB", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"B", "AB"};
    valor = {"AB", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"B", "O"};
    valor = {"O", "B", "A"};
    father_child[tmp] = valor;
    //////
    tmp = {"O", "B"};
    valor = {"AB", "B"};
    father_child[tmp] = valor;
    //////
    tmp = {"AB", "O"};
    valor = {"IMPOSSIBLE"};
    father_child[tmp] = valor;
    //////
    tmp = {"O", "AB"};
    valor = {"IMPOSSIBLE"};
    father_child[tmp] = valor;
    //////
    tmp = {"O", "O"};
    valor = {"O", "B", "A"};
    father_child[tmp] = valor;
}

void pritn_posible_childs()
{
    int l1 = fater.size(),
        l2 = mother.size();
    string aux[4];
    aux[0] = fater.substr(0, l1 - 1),
    aux[1] = mother.substr(0, l2 - 1);
    if (aux[0] > aux[1])
    {
        swap(aux[0], aux[1]);
    }
    cout << fater << " " << mother << " ";
    if (fater[l1 - 1] == '+' || mother[l2 - 1] == '+')
    {
        cout << "{";
        bool flag = false;
        for (auto x : fathers[{aux[0], aux[1]}])
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                cout << ", ";
            }
            cout << x << "-, " << x << "+";
        }
        cout << "}" << endl;
    }
    else
    {
        if (fathers[{aux[0], aux[1]}].size() > 1)
        {
            cout << "{";
            bool flag = false;
            for (auto x : fathers[{aux[0], aux[1]}])
            {
                if (!flag)
                {
                    flag = true;
                }
                else
                {
                    cout << ", ";
                }
                cout << x << "-";
            }
            cout << "}" << endl;
        }
        else
        {
            cout << fathers[{aux[0], aux[1]}][0] << "-" << endl;
        }
    }
}

string print_parents(string parent, string child, int flag)
{
    string cad = "";
    if (father_child[{parent, child}][0] == "IMPOSSIBLE")
    {
        cad += "IMPOSSIBLE";
    }
    else
    {
        bool espacio = false;
        cad += "{";
        for (auto x : father_child[{parent, child}])
        {
            if (!espacio)
            {
                espacio = true;
            }
            else
            {
                cad += ", ";
            }
            if (flag == 1)
            {
                cad += x + "-, " + x + "+";
            }
            else if (flag == 2)
            {
                cad += x + "+";
            }
            else
            {
                cad += x + "-";
            }
        }
        cad += "}";
    }
    return cad;
}

int dobles(string parent, int l1, int l2)
{
    // cout<<parent[l2]<<" "<<child[l1]<<endl;
    if (parent[l1] == '*')
    {
        return 3;
    }
    else if (
        (child == "O+" && parent[l2] == '-') ||
        (parent == "O-" && child[l1] == '+' ||
         (parent[0] != 'O' && child[0] != 'O' && parent[l2] == '-' && child[l1] == '+')))
    {
        return 2;
    }
    return 1;
}

void print_posible_fathers()
{
    string parent;
    if (fater == "?")
    {
        parent = mother;
    }
    else
    {
        parent = fater;
    }
    int l1 = child.size(),
        l2 = parent.size();
    string aux[4];
    aux[0] = child.substr(0, l1 - 1),
    aux[1] = parent.substr(0, l2 - 1);

    string cad = print_parents(aux[1], aux[0], dobles(parent, l1 - 1, l2 - 1));
    if (parent == mother)
    {
        // cout<<"1"<<endl;
        cout
            << cad << " "
            << parent << " "
            << child << endl;
    }
    else
    {
        // cout<<"2"<<endl;
        cout
            << parent << " "
            << cad << " "
            << child << endl;
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    init_faters();
    init_father_child();

    /*for(auto x:fathers){
        cout<<"--"<<x.first.first<<" "<<x.first.second<<endl;
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }*/

    while (cin >> fater >> mother >> child)
    {
        if (fater == "E" && mother == "N" && child == "D")
        {
            break;
        }
        printf("Case %d: ", ++query);
        if (child == "?")
        {
            // cout<<"X"<<endl;
            pritn_posible_childs();
        }
        else
        {
            print_posible_fathers();
        }
    }

    return 0;
}