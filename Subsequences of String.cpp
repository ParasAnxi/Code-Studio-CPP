#include <bits/stdc++.h> 
void solve(string str, string st , int index ,vector<string> &ans){
	if(index>=str.length()){
		if(st.length()>0){
		ans.push_back(st);
		}
		return;
	}
	solve(str,st,index+1,ans);

	char element = str[index];
	st.push_back(element);
	solve(str,st,index+1,ans);
}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string st="";
	int index = 0;
	solve(str,st,index,ans);
	return ans;
}
