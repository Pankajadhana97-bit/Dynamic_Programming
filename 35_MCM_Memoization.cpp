#include<bits/stdc++.h>
using namespace std;

int MCM(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
	int temp;
	int mn = INT_MAX;
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	for (int k=i;k<j;k++){
		temp = MCM(i, k, arr, dp) + MCM(k + 1, j, arr, dp)+(arr[i-1]*arr[k]*arr[j]);
		mn = min(temp, mn);
		} 
		return dp[i][j]=mn;//git init
}
int init(int n,vector<int>&arr){
	int i = 1;
	int j = n - 1;
	vector<vector<int>> dp(1001, vector<int>(1001, -1));
	return MCM(i,j,arr,dp);
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto &x:arr)
	cin>>x;
	cout << init(n, arr) << endl;
	return 0;
}