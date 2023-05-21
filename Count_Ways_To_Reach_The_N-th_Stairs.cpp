#include <bits/stdc++.h>
#define mod 1000000007
int solve(int n, vector<int> &dp) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 2;
  if (dp[n] != -1)
    return dp[n] % mod;

  return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % mod;
}
int countDistinctWays(int nStairs) {
        if(nStairs == 0)
            return 1;
        vector<int> dp(nStairs + 1, -1);
        return solve(nStairs - 1, dp);
}