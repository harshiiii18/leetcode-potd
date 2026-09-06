class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long f=0;
        long long s=0;
        long long ans=0;
        vector<int> temp(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            f+=nums[i];
            temp.push_back(nums[i]);
        }
        for(int i=n/2; i<n; i++){
            s+=nums[i];
            temp.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            f -= temp[i];
            s += temp[i];
            f += temp[i+n/2];
            s -= temp[i+n/2];
            if(f>s){
                ans++;
            }
        }
        return ans;
    }
};