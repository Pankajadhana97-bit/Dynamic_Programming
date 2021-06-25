#include<bits/stdc++.h>
using namespace std;
/**
 *  Dynamic Programming Lecture 34 (Recursion only approach)
 *   /\/\
 *  (^-^ )
 *  (-❤️-)
 **/
 /**  (A)(BCD), (AB)(CD) and (ABC)(D)   //Naive solution moving parenthesis only
 *    so we will have to calculate the -------> arr[i-1]*arr[k]*arr[j] <--------------
 *    so the answers are given by the recursions MCM(i,j,arr)
 *                                                /        \
 *                                          MCM(i,k,arr)+MCM(k+1,j,arr)+(arr[i-1]*arr[k]*p[j])
 * */

int MCM(int i, int j,vector<int>&arr){
	 int min = INT_MAX;
	 int temp;
  	if(i == j)
		return 0;
  	for(int k=i;k<j;k++){
		temp=MCM(i, k, arr)+MCM(k+1,j,arr)+(arr[i-1]*arr[k]*arr[j]);
		if(temp<min){
			min=temp;
		}
	}
	return min;
}

int init(int n,vector<int>&arr){
	int i=1;
	int j=n-1;
	return MCM(i,j,arr);
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto &x:arr)
	cin>>x;
	cout<<init(n,arr);
	return 0;
}