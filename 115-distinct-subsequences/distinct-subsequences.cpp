class Solution {
public:
    int help(int i, int j, vector<vector<int>> &dp, string &s, string &t){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
       
        if(dp[i][j] != -1 ) return dp[i][j];

        int take=0;
        if(s[i]==t[j]){
            take = help(i+1, j+1, dp, s, t);
        }
        int nontake = help(i+1, j, dp, s, t);

        return dp[i][j] = take + nontake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector dp(n, vector<int>(m, -1));
        return help(0, 0, dp, s, t);
    }
};