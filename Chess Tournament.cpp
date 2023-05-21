#include <bits/stdc++.h> 

bool isPossible(int mid,vector<int> p,int c){
   int prev=p[0];
    c--;
    for(int i=1;i<p.size();i++){
      if(p[i]-prev >= mid){
          c--;
          prev=p[i];
      }
        if(c==0)
            return true; 
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	if(positions.size() < c)
          return -1;
    sort(positions.begin(),positions.end());
    int low=1,high=positions[n-1]-positions[0];
    
    while(low<=high){
        int mid=(low+high)/2;
        if(low==mid){
            if(isPossible(high,positions,c)){
                return high;
            }
            return low;
        }
        if(isPossible(mid,positions,c)){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return low;
}