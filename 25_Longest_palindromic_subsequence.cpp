#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string LCS(int n,vector<vector<int>>&dp,string x,string y){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
			   dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
		}
	}
	string ans = "";
	int i = n;
	int j = n;
	while(i>0 and j>0){
		if(x[i-1]==y[j-1]){
			ans+=x[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else{s
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	string str;
	cin >> str;
	//now we will have to find the longest common substring in the string str;
	// the main idea is he have to find the lcs in the str and reverse of the str 
	// ex. aaabbbaa-->bb
	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	int n = str.size();
	vector<vector<int>> dp(n + 1, vector<int>(n+ 1,0));
	cout << LCS(n,dp,str, rev_str);
	return 0;
}