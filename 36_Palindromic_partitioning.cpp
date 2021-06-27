//it is the recursive approach of the palindromic partitioning of the string 
#include<bits/stdc++.h>
using namespace std;

isPalindrome(int i,int j,string s){   //this funtion checks that it is a palindrome or not 
	while(i<j){
		if(s[i]!=s[j])
			return 0;
		i++;
		j--;
	}
	return true;
}

int palindromicpartition(string s,int i,int j){      //this basically partioned the string into palindrome
	int temp, mn = INT_MAX;
	if( i==j or isPalindrome(i,j,s))     //if the string is already a palindrome or reaches base condition return 0
		return 0;

	for (int k = i; k < j;k++){
		temp = 1 + palindromicpartition(s, i, k) + palindromicpartition(s, k + 1, j);
		mn = min(mn, temp);
	}
	return mn;
}
int main(){
	string str;
	cin>>str;
	int i = 0;
	int j = str.size() - 1;
	cout<<palindromicpartition(str,i,j); //utility function for returning partitions
	return 0;
}
