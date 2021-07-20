#include<bits/stdc++.h>
using namespace std;

// I am only going to write the utility function 

int maxPath(node* root,int &res){
	if(!root) return 0;

	int l=maxPath(root->left,res);
	in  r=maxPath(root->right,res);

	int temp=max(max(l,r)+root->data,root->data);
	int max_top=max(temp,l+r+root->data);
	
	res=max(res,max_top);
	return temp;
}