#include<bits/stdc++.h>
using namespace std;
void solve(int n,char s,char h,char d){
    if(n==0)return;
    solve(n-1,s,d,h);
    cout<<"Move "<<s<<" to "<<d<<endl;
    solve(n-1,h,s,d);
}
int main(){
    int n;
    cout<<"Enter number of disk"<<endl; 
    cin>>n;
    
    solve(n,'A','B','C');
    return 0;

}