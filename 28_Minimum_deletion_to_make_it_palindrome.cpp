#include<bits/stdc++.h>
using namespace std;
/*
 * here the thinking is that we will have t find the longest palindromic subsequnce 
 * so that we will hav to delete the minimum number if the elements to make it palindrome 
 *  Example -: let say we have a string 
 *        aamras    ------ (Reverse of the aamras is )  ----- sarmaa
 *         so the palindrome of the aamras is  ama 
 *         so we will have to perform n-Sizeof(lps)=6-3=3; 
 */

int LPS(int n,string x,string y,vector<vector<int>>&dp){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][n];
}
int main(){
	string s;
	cin >> s;
	string r = s;
	reverse(r.begin(),r.end());
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	cout << n-LPS(n, s, r, dp);
}