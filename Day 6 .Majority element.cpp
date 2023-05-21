#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i:m){
        if(i.second>n/2)
            return i.first;
    }
    return -1;
}