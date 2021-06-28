#include<bits/stdc++.h>
using namespace std;
#define int long long

int knapsack(int n,int w,int value[],int wt[],vector<vector<int>>&dp){
          for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
               if(i==0 or j==0) dp[i][j]=0;

               else if(wt[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+value[i-1]);
              else 
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
void solve(){
  int n=3;
  //cin>>n;
  int w=4;
  //cin>>w;
  int value[]={1,2,3};
  int wt[]={4,5,1};
  for(auto &x:value)cin>>x;
  for(auto &y:wt)cin>>y;
  vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
  cout<<knapsack(n,w,value,wt,dp); 
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
   // cin>>T;
    while(T--){
        solve();
    }
  cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<" sec\n";
}


// int knapsack(int n,int w,int value[],int wt[],vector<vector<int>>&dp){
//   //according to the question 
//    if(n==0 or w==0) return dp[n][w]=0;

//    if(dp[n][w]!=-1) return dp[n][w];
//   else if(wt[n-1]<=w)
//   return dp[n][w]=max(value[n-1]+knapsack(n-1,w-wt[n-1],value,wt,dp),knapsack(n-1,w,value,wt,dp));
//   return dp[n][w]=knapsack(n-1,w,value,wt,dp);
// }