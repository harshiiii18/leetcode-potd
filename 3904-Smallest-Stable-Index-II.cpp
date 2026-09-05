// Intuition
// The intuition behind this problem is question directly say nums[0..i] max and 
// nums[i..n-1] min so the first intution is prefix-suffix solution solve the problem,
// so calculate each nums[i] prefixMax and SuffixMin and calculate score when score less 
// than and equal to k then store that index in ans and return the ans.

// Complexity
// Time complexity: O(n)
// Space complexity: O(n)


// leetcode solution
// {https://leetcode.com/problems/smallest-stable-index-ii/solutions/8504203/simple-c-solution-clean-code-by-codewith-rlr3}

// Code
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n, 0);
        vector<int> suffixMin(n, 0);

        prefixMax[0]=nums[0];
        for(int i=1; i<n; i++){
         prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }
        
        suffixMin[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        int smallIdx=-1;
        for(int i=0; i<n; i++){
            int s = prefixMax[i]-suffixMin[i];
            if(s<=k){
                smallIdx=i;
                break;
            }
        }
        return smallIdx;
    }
};