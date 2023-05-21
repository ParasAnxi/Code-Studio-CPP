#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr){
unordered_map<int,int>mp;
   for(int i=0;i<arr.size();i++)
   {
       mp[arr[i]]++;
   }
    vector<int>v;
   for(auto it:mp)
   {
       if(floor(arr.size()/3)<it.second)
       {
           v.push_back(it.first);
       }
   }
   return v;
}