#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
sort(intervals.begin(),intervals.end());
         vector<vector<int>>ans;
         int currStart=intervals[0][0];
         int currEnd=intervals[0][1];
         for(int i=1;i<intervals.size();i++){
             int newStart=intervals[i][0];
             int newEnd=intervals[i][1];
             if(newStart<=currEnd){
                 currEnd=max(currEnd,newEnd);
             }
             else{
                 ans.push_back({currStart,currEnd});
                 currStart=newStart;
                 currEnd=newEnd;
             }
         }
         ans.push_back({currStart,currEnd});
         return ans;
         }
