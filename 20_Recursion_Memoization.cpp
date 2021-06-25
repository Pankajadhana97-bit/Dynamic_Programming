#include<iostream>
#include<vector>
using namespace std;

int LCS(vector<vector<int>> &dp,string X,string Y,int n,int m){
	if(n==0 or m==0)   //Base Condition 
		return dp[n][m]= 0;
	if(dp[n][m]!= -1)
		return dp[n][m]; //Memoization 
	if(X[n-1]==Y[m-1])
		return dp[n][m]=1 + LCS(dp,X, Y, n - 1, m - 1);  //if character is same then decrement by 1
	return  dp[n][m]=max( LCS(dp,X, Y, n - 1, m ), LCS(dp,X, Y, n , m - 1));  // Return to the another Condition where it is feasible 
}
int main(){
	string s;
	string str;
	cin >> s >> str;
	int n = s.size();
	int m = str.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	cout << LCS(dp, s, str, n, m);
	return 0;
}