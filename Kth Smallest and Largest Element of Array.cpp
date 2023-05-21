#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> v;
	sort(arr.begin(),arr.end());
	v.push_back(arr[k-1]);
	v.push_back(arr[n-k]);
	return v;
}