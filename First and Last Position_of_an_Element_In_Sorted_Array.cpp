#include <bits/stdc++.h> 
int firstOcc(vector<int>& arr,int size,int key){
    int s=0;
    int ans= -1;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastOcc(vector<int>& arr,int size,int key){
    int s=0;
    int ans= -1;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
        pair<int,int> p;
        p.first=firstOcc(arr,n,k);
        p.second=lastOcc(arr,n,k);
        return p;

}