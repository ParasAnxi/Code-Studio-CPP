#include <bits/stdc++.h> 
bool targetAns(vector<vector<int>> mat,int s,int e,int n,int target)
{
    int mid=s+(e-s)/2;
    if(s>e)
    return false;
    if(mat[mid/n][mid%n]==target)
    return true;
    else if(mat[mid/n][mid%n]<target)
    s=mid+1;
    else
    e=mid-1;
    return targetAns(mat,s,e,n,target);
}
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int e=m*n-1;
    int s=0;
    bool ans=targetAns(mat,s,e,n,target);
    return ans;
}