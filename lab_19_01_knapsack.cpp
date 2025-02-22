#include <bits/stdc++.h>
using namespace std;

int Knapsack(vector<pair<int, int>> &items, int n, int m)
{
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        int weight=items[i-1].first;
        int profit=items[i-1].second;
    
        for(int w=0;w<=m;w++)
        {
            if(i==0||w==0)
              dp[i][w]=0;
              else if(w<weight)
              dp[i][w]=dp[i-1][w];
              else
              dp[i][w]=max(dp[i-1][w],dp[i-1][w-weight]+profit);
        }
    }
    return dp[n][m];

}

int main()
{
    int n, m;
    cout << "Enter number of items:";
    cin >> n;
    cout << "Enter the maximum weight of knapsack:";
    cin >> m;
    vector<pair<int, int>> items(n);
    cout << "Enter weights and profit of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }
    int maxProfit = Knapsack(items, n, m);
    cout << "Maximum profit can be obtained:" << maxProfit << endl;

    return 0;
}