class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX); // dp[i] = min length ending at or before i
        int l = 0, sum = 0;
        int ans = INT_MAX;
        
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l];
                l++;
            }
            
            int prevBest = (l == 0) ? INT_MAX : dp[l - 1];
            
            if (sum == target) {
                int curLen = r - l + 1;
                if (prevBest != INT_MAX) {
                    ans = min(ans, prevBest + curLen);
                }
                dp[r] = min((r == 0) ? INT_MAX : dp[r - 1], curLen);
            } else {
                dp[r] = (r == 0) ? INT_MAX : dp[r - 1];
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};