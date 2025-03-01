#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>>&item,int n,int wt){
    sort(item.begin(),item.end(),[](pair<int,int>a,pair<int,int>b){
        return (double)a.second/a.first>(double)b.second/b.first;
    });
    double maxprofit=0.0;
    for(auto &it:item){
        int weight=it.first;
        int profit=it.second;
        if(weight<wt){
            maxprofit+=profit;
            wt-=weight;
        }
        else{
            maxprofit+=(double)wt/weight*profit;
            break;
        }
    }
    return maxprofit;

}
int main(){
    int n;
    cout<<"Enter number of item:"<<endl;
    cin>>n;
    vector<pair<int,int>>item(n);
     cout<<"Enter weight and profit:"<<endl;
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }
    int wt;
    cout<<"Enter maximum capacity :"<<endl;
    cin>>wt;
   
    cout<<"maxprofit "<<solve(item,n,wt);
}