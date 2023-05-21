#include<bits/stdc++.h> 

bool check(int m,int n){
if(m<0 or n<0) return false;
return true;
}

int solve(int m,int n,vector<vector<int>> &dp){
	if(m==0 and n==0) return 1;
    if(dp[m][n]!=-1)  return dp[m][n];
    int l=0;
	if(check(m,n-1)==true)  l=solve(m,n-1,dp);
    int r=0;
	if(check(m-1,n)==true)  r=solve(m-1,n,dp);
	return dp[m][n]=l+r;
	

}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
	return solve(m-1,n-1,dp);

}