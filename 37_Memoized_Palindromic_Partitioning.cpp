/*
Given a string, a partitioning of the string is a palindrome partitioning if every
substring of the partition is a palindrome. For example, "aba|b|bbabb|a|b|aba" is a palindrome
partitioning of "ababbbabbababa". Determine the fewest cuts needed for a palindrome partitioning of
 a given string. For example, minimum of 3 cuts are needed for "ababbbabbababa". The three cuts are
"a|babbbab|b|ababa". If a string is a palindrome, then minimum 0 cuts are needed. If a string of 
length n containing all different characters, then minimum n-1 cuts are needed. 
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
	while(i<j){
		if(s[i]!=s[j])
			return false;
		i++;
		j--;
	}
	return true;
} //  basic utility function to check string is palindromic or not 
int Palindromicpartition(string s,int i,int j,vector<vector<int>>&dp){
	if(i==j or isPalindrome(s,i,j))
		return dp[i][j]=0;

		if(dp[i][j]!= -1)
			return dp[i][j];

		int temp, mn = INT_MAX;
		for (int k = i; k < j;k++){
			int l, r;

			if(dp[i][k]!= -1) l=dp[i][k];
			else l = Palindromicpartition(s, i, k, dp);

			if(dp[k+1][j]!= -1) r=dp[k+1][j];
			else	r = Palindromicpartition(s, k + 1, j, dp);

			temp = 1 + l + r;
			mn = min(mn, temp);
		}
		return dp[i][j] = mn;
}    //that is the main function which returns the partitions in the string we have performed till now 
int main(){
	string str;
	cin>>str;
	int i = 0;
	int j=str.size()-1;
	vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, -1));
	cout << Palindromicpartition(str,i,j,dp);
	return 0;
}