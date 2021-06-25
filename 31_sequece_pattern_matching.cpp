#include<bits/stdc++.h>
using namespace std;

bool Pattern_search(int n,int m,string x,string y,vector<vector<int>>&dp){
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= m;j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
   if(dp[n][m]==x.size())
		 return true;

	 return false;
}
int main(){
	string x, y;
	cin>>x>>y;
	int n = x.size();   // Let say we will have to find the pattern x in the y
	int m = y.size();   // y is here given as the full string

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Matrix initialised with the zeroes 
	cout<<(Pattern_search(n, m, x, y, dp)?"YES":"NO");
	cout << endl;
	return 0;
}
/**
 * class Solution {
    
    int LCS(int n,int m,string s,string t){
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=false;
        for(int j=0;j<=m;j++)dp[0][j]=false;
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];  
    }
public:
    bool isSubsequence(string s, string t) {
    //this problem is belong to longest common subsequence 
       int n=s.size();
       int m=t.size();
        if(LCS(n,m,s,t)==n)return true;
        return false;   
    }
};
 * 
 * Leetcode question 392 
 * Link-> https://leetcode.com/problems/is-subsequence/
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */