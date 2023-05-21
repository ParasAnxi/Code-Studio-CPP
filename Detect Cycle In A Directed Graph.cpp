#include<bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>>adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v =edges[i].second - 1;
        adj[u].push_back(v);
    }
    vector<int> inDegree(n);
    for(auto i : adj){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    queue<int> q;
    for(int i = 0; i<n;i++){
        if(inDegree[i] == 0)
            q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;

            for(auto neighbour : adj[front]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        if(count == n) return false;
        else return true;
    }
