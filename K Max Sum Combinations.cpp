#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    vector<int> res;
    
    vector<vector<int>> m(n, vector<int>(n, 0));
    maxHeap.push({a[0]+b[0], {0, 0}});
    m[0][0] = 1;
    
    //O(klogN)
    while(k--){
        int topVal = maxHeap.top().first;
        int i = maxHeap.top().second.first;
        int j = maxHeap.top().second.second;
        res.push_back(topVal);
        maxHeap.pop();
        
        if(j+1<n && m[i][j+1]==0) {
            maxHeap.push({a[i]+b[j+1], {i, j+1}});
            m[i][j+1] = 1;
        }
        if(i+1<n && m[i+1][j]==0){
            maxHeap.push({a[i+1]+b[j], {i+1, j}});
            m[i+1][j] = 1;
        }
    }
    
    return res;
}