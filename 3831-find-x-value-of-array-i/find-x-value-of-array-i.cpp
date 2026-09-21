class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);

        // prefix[r] = current position se pehle tak
        // ending subarrays jinka product % k = r
        vector<long long> prefix(k, 0);

        for (int num : nums) {

            vector<long long> newPrefix(k, 0);

            int x = num % k;

            // Sirf current element wala subarray
            newPrefix[x]++;

            // Previous subarrays ko current element ke saath extend karo
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * x) % k;

                newPrefix[newRemainder] += prefix[r];
            }

            // Current position par banne wale
            // saare subarrays answer me add karo
            for (int r = 0; r < k; r++) {
                ans[r] += newPrefix[r];
            }

            prefix = newPrefix;
        }

        return ans;
    }
};


// class Solution {
// public:
//     vector<long long> resultArray(vector<int>& nums, int k) {
//         vector<long long> ans(k, 0);
//         int n = nums.size();

//         vector<long long> prefix(n, 1);
//         prefix[0] = nums[0];
//         ans[nums[0] % k]++;
//         for(int i=1; i<n; i++){
//           prefix[i] = prefix[i-1] * nums[i];
//           ans[prefix[i] % k]++;
//         }
        
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 long long res = prefix[j] / prefix[i];
//                 ans[res % k]++;
//             }
//         }
//         return ans;
//     }
// };