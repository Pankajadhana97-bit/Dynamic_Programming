#include<bits/stdc++.h>
using namespace std;

/*
//Recursion only
int LCS(int n,int m,string x,string y){
	   if(m==0 or n==0)return 0;
       if(x[n-1]==y[m-1])
	   return 1+LCS(n-1,m-1,x,y);
	   return max(LCS(n-1,m,x,y),LCS(n,m-1,x,y));
}
*/

/*
//  Recursion +memoization 
int LCS(vector<vector<int>>&dp,int n,int m,string x,string y){
	if(m==0 or n==0)
		return dp[n][m]= 0;
	if(dp[n][m]!= -1)
		return dp[m][n];
	if(x[n-1]==y[m-1])
	  return dp[n][m]=1+LCS(dp,n-1,m-1,x,y);
	 return dp[n][m]=max(LCS(dp,n,m-1,x,y), LCS(dp,n-1,m,x,y));
}
*/

string LCS(vector<vector<int>>&dp,int n,int m,string x,string y){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= m;j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
				else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = n;
	int j = m;
	string ans = "";
	while(i>0 and j>0){
		if(x[i-1]==y[j-1])
		 {
			 ans += x[i - 1];
			 i--;
			 j--;
		 }
		 else if(dp[i-1][j]>dp[i][j-1]){
			 i--;
		 }
		 else{
			 j--;
		 }
	}
	while(i>0){
		ans += x[i - 1];
		i--;
	}
	while(j>0){
		ans += y[j - 1];
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	string x, y;
	cin>>x>>y;
	int n = x.size();
	int m = y.size();
	//vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); //in case of Memoization
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // in case of the simple dp approach 
	cout<<LCS(dp,n, m, x, y)<<endl; //Longest common super sequence 
	return 0;
}

