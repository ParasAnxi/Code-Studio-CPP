#include <bits/stdc++.h> 
vector<vector<int>> ans;
bool possible(int x, int y, vector<vector<int>> &maze, int n){
    return (x >=0 and x < n and y >= 0 and y < n and maze[x][y] == 1);
}
void appendToPaths(vector<vector<int>> &path, int n){
    vector<int> v;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v.push_back(path[i][j]);
    ans.push_back(v);
}
void solve(vector<vector<int>> &maze, int x, int y, int n, vector<vector<int>> &path){
    if(x == n-1 and y == n-1){
        path[x][y]++;
        appendToPaths(path, n);
        path[x][y]--;
        return;
    };
    path[x][y]++;
    maze[x][y]++;
    if(possible(x, y-1, maze, n)) solve(maze, x, y-1, n, path);
    if(possible(x-1, y, maze, n)) solve(maze, x-1, y, n, path);
    if(possible(x, y+1, maze, n)) solve(maze, x, y+1, n, path);
    if(possible(x+1, y, maze, n)) solve(maze, x+1, y, n, path);
    maze[x][y]--;
    path[x][y]--;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n){
    vector<vector<int>> path(n, vector<int> (n, 0));
    solve(maze, 0, 0, n, path);
    return ans;
}