#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

void bfs(int startNode,int adj[MAX_SIZE][MAX_SIZE],int visited[MAX_SIZE],int n)
{
    queue<int>q;
    visited[startNode]=1;
    q.push(startNode);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        for(int j=0;j<n;j++)
        {
             if(adj[node][j]==1 && visited[j]==0)
             {
                visited[j]=1;
                q.push(j);
             }   
        }
    }

}
int main()
{
   int n;
   cout<<"Enter the number of vertex : "<<endl;
   cin>>n;
   int adj[MAX_SIZE][MAX_SIZE],visited[MAX_SIZE];
   cout<<"Enter the adjacency matrix : "<<endl;
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
   }
   for(int i=0;i<n;i++)
   {
       visited[i]=0;
   }
   int startNode=0;
   bfs(0,adj,visited,n);


    return 0;
}