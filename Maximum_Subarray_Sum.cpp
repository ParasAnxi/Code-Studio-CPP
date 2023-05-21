#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n){
    long long currSum = 0;
    long long mx = INT_MIN;
    for( int i = 0; i < n; i++){
        currSum += arr[i];
        if( currSum < 0){
            currSum = 0;
        }
        mx = max( currSum , mx );
    }
    return mx;
}