#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int>p;
	int index=0;
	while(index<n){
		if(arr[index]==index+1){
			index++;
			continue;
		}
		else if(arr[index]==arr[arr[index]-1]){
			p.second=arr[index];
			index++;
			continue;
		}
		else{
			swap(arr[index],arr[arr[index]-1]);
		}
	}
	int i=0;
	while(i<n && arr[i]==i+1){
		i++;
	}
	p.first=i+1;
	return p;
}
