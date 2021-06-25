#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int n,int m){
	if(n==0 or m==0)   //Base Condition 
		return 0;
	if(X[n-1]==Y[m-1])
		return 1 + LCS(X, Y, n - 1, m - 1);  //if character is same then increment by 1
	return max( LCS(X, Y, n - 1, m ), LCS(X, Y, n , m - 1));  // Return to the another Condition where it is feasible 
}
int main(){
	string s;
	string str;
	cin >> s >> str;
	int n = s.size();
	int m = str.size();
	cout << LCS(s, str,n,m);
	return 0;
}