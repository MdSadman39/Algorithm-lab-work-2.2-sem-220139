#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &graph, int n)
{
    vector<int> temp;
    for (int i = 1; i < n; i++)
    {
        temp.push_back(i);
    }
    int mincost = INT_MAX;
    do
    {
        int curentcity = 0;
        int curentcost = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            curentcost += graph[curentcity][temp[i]];
            curentcity = temp[i];
        }
        curentcost += graph[curentcity][0];
        mincost = min(mincost, curentcost);
    } while (next_permutation(temp.begin(), temp.end()));
    return mincost;
}
int main()
{
    int n;
    cout << "Enter number of city:" << endl;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Minimumn cost= " << solve(graph, n);
}