#include<bits/stdc++.h>
using namespace std;
int equalPartition(int N, int arr[],int K)
    {
        int dp[N+1][K+1];
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=K;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
               if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];   //inplace of 'or' we are adding '+' sign only 
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return(dp[N][K]);
    }
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    int reqsum;
    cin >> reqsum;
    cout<<equalPartition(n,arr,reqsum);
}