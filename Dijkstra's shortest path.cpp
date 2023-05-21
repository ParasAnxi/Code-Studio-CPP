#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i = 0; i< edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>dis(vertices);
    for(int i = 0 ; i<vertices;i++)
        dis[i] = INT_MAX;

    set<pair<int,int>>st;
    dis[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[topNode]){
            if(nodeDistance+neighbour.second<dis[neighbour.first]){
                auto record = st.find(make_pair(dis[neighbour.first],neighbour.first));

                if(record!=st.end()){
                    st.erase(record);
                }
                dis[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dis[neighbour.first],neighbour.first));
            }
        }
    }
    return dis;
}
