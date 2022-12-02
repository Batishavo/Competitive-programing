// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int pi[10] = {0, 1, 0, -1},
        pj[10] = {1, 0, -1, 0};

    vector<vector<int>> res;
    vector<vector<char>> mat;

    void bfs(int a, int b, int n, int m)
    {

        deque<pair<int, int>> cola;
        cola.push_front({a, b});
        while (!cola.empty())
        {

            pair<int, int> actual = cola.front();
            cola.pop_front();

            int i = actual.first,
                j = actual.second;

            // printf("%d %d\n", i, j);

            for (int k = 0; k < 4; k++)
            {
                if (i + pi[k] >= 0 && i + pi[k] < n && j + pj[k] >= 0 && j + pj[k] < m)
                {

                    // printf("**%d %d\n", i+pi[k], j+pj[k]);

                    if (mat[i + pi[k]][j + pj[k]] == 'H' || mat[i + pi[k]][j + pj[k]] == '.')
                    {
                        // cout<<mat[i+pi[k]][j+pj[k]]<<endl;
                        if (res[i + pi[k]][j + pj[k]] == -1 ||
                            res[i + pi[k]][j + pj[k]] > res[i][j] + 2)
                        {
                            // printf("%d %d \n",i+pi[k],j+pi[k]);
                            cola.push_back({i + pi[k], j + pj[k]});
                            res[i + pi[k]][j + pj[k]] = res[i][j] + 2;
                        }
                    }
                    else if (mat[i + pi[k]][j + pj[k]] == 'W')
                    {
                        res[i + pi[k]][j + pj[k]] = 0;
                        cola.push_front({i + pi[k], j + pj[k]});
                    }
                }
            }
        }
    }

    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
    {
        // Code here
        mat.clear();
        vector<char> aux;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                aux.push_back(c[i][j]);
            }
            mat.push_back(aux);
            aux.clear();
        }
        res.clear();
        res = vector<vector<int>>(n + 10, vector<int>(m + 10, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 'W')
                {
                    res[i][j] = 0;
                    bfs(i, j, n, m);
                }
                else if (mat[i][j] == 'N')
                {
                    res[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == '.')
                {
                    res[i][j] = 0;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res = ob.chefAndWells(n, m, c);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
} // } Driver Code Ends