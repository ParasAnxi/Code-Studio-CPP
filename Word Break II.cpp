#include <bits/stdc++.h>
void solve(string s,unordered_set<string>& mp,vector<string>& v,string ans){
    if(s.size()==0){
        ans.pop_back();
        v.push_back(ans);
        return;
    }
    for(int i=1;i<=s.size();i++){
        if(!mp.count(s.substr(0,i)))continue;
        solve(s.substr(i),mp,v,ans+s.substr(0,i)+" ");
    }
}     
vector<string> wordBreak(string &s, vector<string> &wordDict)
{
    // Write your code here
            unordered_set<string> mp;
        mp.insert(wordDict.begin(),wordDict.end());
        vector<string> v;
        string ans = "";
        solve(s,mp,v,ans);
        return v;

}