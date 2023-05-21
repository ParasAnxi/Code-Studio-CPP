#include <bits/stdc++.h> 
int uniqueElement(vector<int> arr, int n)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start )/2;
    while (start < end){
          if (mid % 2 == 0) {
            if(arr[mid] == arr[mid +1]){
            start = mid + 2 ;
            } 
            else
            end = mid ;
          }
          else {
            if (arr[mid] == arr[mid - 1]) {
              start = mid + 1;
            } else
              end = mid - 1;
          }
          mid = start + (end - start )/2;
        }
                  return arr[start];
}