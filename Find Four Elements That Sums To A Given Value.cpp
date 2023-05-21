#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-3; i++){
        for(int j = i+1; j < n-2; j++){
            int k = j+1;
            int z = n-1;

            while(z > k){
                if(arr[i]+arr[j]+arr[k]+arr[z] == target){
                    return "Yes";
                }
                else if(arr[i]+arr[j]+arr[k]+arr[z] > target){
                    z--;
                }
                else{
                    k++;
                }
            }
        }
    }
    return "No";
}