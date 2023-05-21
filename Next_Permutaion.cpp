#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if(permutation.size()<=1)return permutation;
    vector<int>v;
    int i=0;
    do{
    i++;
    if(i==2){
        for(auto x:permutation){
            v.push_back(x);
        }
        break;
    }
    }while(next_permutation(permutation.begin(),permutation.end()));
    if(v.size()==0){
        sort(permutation.begin(),permutation.end()); 
        return permutation;
    }
    return v;
}