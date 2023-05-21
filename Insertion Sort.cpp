#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    int i =1;
    while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        i++;
        arr[j+1]=temp;
    }
}