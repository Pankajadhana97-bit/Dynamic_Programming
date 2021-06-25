#include<bits/stdc++.h>
using namespace std;

 /**
 *   here the problem idea is that we will hsve to find the number of(insertions or deletions #both are same) 
 *   to make the string palindrome letsay  aabcb to make it a palindrome we will have to add 'aa' in hte last or 
 *   another choice is that we can delete 'aa' from the beginning of the string beacause both of them are palindrome   
 *   and taking equal number of the steps  
 *   Palindromes are (aabcbaa) and (bcd) 
 * */

int lcs(int n,string x,string y,vector<vector<int>>&dp){

	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
				else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][n];
}
int main(){
	string str;
	cin >> str;
	int n=str.size();
	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	vector<vector<int> >dp(n+1,vector<int>(n+1,0));
	cout<<"The minimum no. of the del/insertion in the string to make it a palindrome is -> "<< n-lcs(n,str,rev_str,dp)<<endl;
	return 0;
}