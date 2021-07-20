#include<bits/stdc++.h>
using namespace std;

// it is the lcs only we will implement the longest substring 

int LongestCommonSubstring(vector<vector<int>>&dp,int n,int m,string x,string y){

	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= m;j++){
			if(x[i]==y[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	return dp[n][m];
}
int main(){
	string x;
	string y;
	cin >> x >> y;
	int n = x.size();
	int m = y.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	for (int i = 0; i <= n;i++)
		dp[i][0] = 0;
	for (int j = 1; j <= m;j++)
		dp[0][j] = 0;
		cout<< LongestCommonSubstring(dp, n, m, x, y);
}