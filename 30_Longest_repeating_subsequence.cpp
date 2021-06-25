#include<bits/stdc++.h>
using namespace std;

int LRS(int n,string x,vector<vector<int>>&dp){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			if(x[i-1]==x[j-1] and i!=j){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][n];
}
int main(){
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	cout << LRS(n, s, dp);
	return 0;
}