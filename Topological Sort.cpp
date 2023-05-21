#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adj;
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v =edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> inDegree(v);
    for(auto i : adj){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    queue<int> q;
    for(int i = 0; i<v;i++){
        if(inDegree[i] == 0)
            q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto neighbour : adj[front]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return ans;
    }
