vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(vector<int> a: q){
        if(a[0] == 0){
            pq.push(a[1]);
        }
        if(a[0]==1){
            v.push_back(pq.top());
            pq.pop();
        }
    }
    return v;
}