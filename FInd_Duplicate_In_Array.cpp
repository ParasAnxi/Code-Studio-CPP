#include <bits/stdc++.h> 
using namespace std;
int findDuplicate(vector<int> &nums, int n){
       sort(nums.begin(),nums.end());
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!= fast);

        fast = nums[0];
        while(slow!= fast)
        {   
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        return slow;
}
