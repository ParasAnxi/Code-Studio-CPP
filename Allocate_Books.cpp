#include <bits/stdc++.h>
int isPossible(vector<int> arr, int n, int m, int mid)
{
    int student = 1;
    int page = 0;
    for (int i = 0; i < n; i++)
    {
        if (page + arr[i] <= mid)
        {
            page += arr[i];
        }
        else
        {
            student++;
            if (student > m || arr[i] > mid)
            {
                return false;
            }
            page = arr[i];
        }
    }
    return true;
}
int allocateBooks(vector<int> arr, int n, int m)
{
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}