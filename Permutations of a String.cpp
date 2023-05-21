#include<algorithm>
void solve(string str , int index , vector<string>& ans){
    if(index==str.length()-1){
        ans.push_back(str);
        return;
    }
    for(int i = index; i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,index+1,ans);
        swap(str[index],str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    int index = 0;
    vector<string> ans;
    solve(str,index,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

