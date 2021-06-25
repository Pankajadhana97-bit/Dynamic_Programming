#include<bits/stdc++.h>
using namespace std;
#define int long long 
int knapsack(vector<vector<int>>&dp,vector<int>wt,vector<int>val,int w,int n){
   if(n==0 or w==0)return 0;
   if(dp[n][w]!= -1)
   return dp[n][w];
   if(wt[n-1]<=w){
     dp[n][w]=max(val[n-1]+knapsack(dp,wt,val,w-wt[n-1],n-1),knapsack(dp,wt,val,w,n-1));
   }
   else if(wt[n-1]>w) dp[n][w]=knapsack(dp,wt,val,w,n-1);
   return dp[n][w];
}
void solve(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    vector<int>wt(n);
    vector<int>val(n);
    for(auto &x:wt)cin>>x;
    for(auto &y:val)cin>>y;
    cout<<knapsack(dp,wt,val,w,n)<<endl;    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--)
    {
    solve();
    }
   return 0;
}