int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>cnt;
    int maxFreq = 0;
    int maxAns = 0;
    for(int i = 0 ;i<arr.size();i++){
        cnt[arr[i]]++;
        maxFreq = max(maxFreq,cnt[arr[i]]);
    }
    for(int i = 0 ; i<arr.size();i++){
        if(maxFreq == cnt[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}