#include<bits/stdc++.h>
using namespace std;

int findmin(vector<int>&arr,int n){
	int sum = 0;
	for (int i = 0; i < n;i++)
		sum += arr[i];

	int dp[n + 1][sum + 1];
	for (int i = 0; i <= n;i++)
		dp[i][0] = true;
	for (int j = 1; j <= sum;j++)
		dp[0][j] = false;

	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= sum;j++){
			if(arr[i-1]<=j)
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
				else
					dp[i][j] = dp[i - 1][j];
		}
	}                                                                  //for range we will have to check only the last row of the matrix 
	int diff = INT_MAX;
	for (int j = 0; j <= sum / 2;j++){    //here j represents the sum
		          if(dp[n][j]==true){
					  diff = min(sum - 2*j, diff);
				  }
	}
	return diff;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int i = 0; i < n;i++)
		cin >> arr[i];
		cout << findmin(arr, n);
	return 0;
}