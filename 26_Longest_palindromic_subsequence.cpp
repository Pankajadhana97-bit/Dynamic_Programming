#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string LPS(int n,string x,string y,vector<vector<int>>&dp){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			if(x[i-1]==y[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
				else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = n;
	int j = n;
	string ans = "";
	while(i>0 and j>0){
		if(x[i-1]==y[j-1]){
			ans += x[i - 1];
			i--;
			j--;
		}
		else 
		    if(dp[i- 1][j]>dp[i][j-1])
			i--;
			else
			j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	string str;
	cin>>str;
	string revstr = str;
	reverse(revstr.begin(),revstr.end());
	int n = str.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	cout << LPS(n, str, revstr,dp);
}