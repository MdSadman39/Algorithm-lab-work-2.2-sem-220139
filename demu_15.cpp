#include <bits/stdc++.h>
using namespace std;

void primMST(int N, vector<vector<pair<int, int>>> &adj)
{
    vector<int> parent(N, -1);
    vector<int> key(N, INT_MAX);
    vector<bool> inMST(N, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0]=0;
    pq.push({0,0});//{weight,node}
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        inMST[u]=true;

        for (auto [v, weight] : adj[u])
        {
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
        
            

    }
     for (int i = 1; i < N; i++)
    cout << parent[i] << " - " << i << "\n";
}

int main()
{
    int N, m;
    cin >> N >> m;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    primMST(N, adj);

    return 0;
}