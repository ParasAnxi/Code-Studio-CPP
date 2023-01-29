int isPossible(vector<int> &stalls, int k, int mid)
{

    int cow = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cow++;
            if (cow == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxx = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxx = max(maxx, stalls[i]);
    }
    int end = maxx;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}