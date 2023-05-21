#include <bits/stdc++.h> 
using namespace std; 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int count = 1;
    int count_max = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i-1])
        {
            continue;
        }
        else if(arr[i] == (arr[i-1] + 1))
        {
            count++;
        }
        else
        {
            count = 1;
        }
        count_max = max(count_max, count);
    }
    return count_max;
}