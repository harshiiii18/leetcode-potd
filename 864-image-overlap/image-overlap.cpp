class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2,
                int row_offset, int col_offset) {
        int cnt = 0;
        int n = img1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + row_offset >= 0 && j + col_offset >= 0 &&
                    row_offset + i < n && col_offset + j < n) {
                    if (img2[i][j] == 1 && img1[i + row_offset][col_offset + j] == 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int ans = 0;
        int n = img1.size();
        for (int row_offset = -n + 1; row_offset < n; row_offset++) {
            for (int col_offset = -n + 1; col_offset < n; col_offset++) {
                ans = max(ans, overlap(img1, img2, row_offset, col_offset));
            }
        }
        return ans;
    }
};