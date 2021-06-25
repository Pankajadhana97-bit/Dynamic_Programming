#include<bits/stdc++.h>
using namespace std;

void LCS(int n,int m,string x,string y){

	int dp[n + 1][m + 1];
	for (int i = 0; i <= n;i++){
		for (int j = 0; j <= m;j++){
			if(i==0 or  j==0)
				dp[i][j] = 0;

			else if(x[i-1]==y[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	/*
   This is the  main problem here 
   the crux is that we will have to form the string which is common in both 
	*/
	int val = dp[m][n];
	string lcs = "";

	int i = n;
	int j = m;

	while(i>0 and j>0){
		if(x[i-1]==y[j-1]){
			lcs += x[i - 1];
			i--;
			j--;
			val--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		i--;
		else
		j--;
	}
	reverse(lcs.begin(), lcs.end());
	cout << lcs << endl;
}
int main(){
	string x;
	cin >> x;
	string y;
	cin >> y;
	int n = x.size();
	int m = y.size();
	LCS(n, m, x, y);
}