#include <bits/stdc++.h> 
int getMin(int *arr ,int n){
	int mini = INT_MAX;
	for(int i = 0;i<n;i++){
		mini = min(mini,arr[i]);
	}
	return mini;
}
int getMax(int *arr ,int n){
	int maxi = INT_MIN;
	for(int i = 0;i<n;i++){
		maxi = max(maxi,arr[i]);
	}
	return maxi;
}
int sumOfMaxMin(int arr[], int n){
	int mini = getMin(arr,n);
	int maxi = getMax(arr,n);
	int result = mini+maxi;
	return result;
}