class Solution {
public:
    vector<int> first, last;
    int n;
    // memo[i] = {best count, best (min) length} achievable using s[i..n-1]
    vector<pair<int,int>> memo;
    vector<bool> computed;

    pair<int,int> f(int i, string &s){
        if(i >= n) return {0, 0};
        if(computed[i]) return memo[i];

        // not take
        pair<int,int> skip = f(i+1, s);

        // take — check validity + find closed interval end
        int end = last[s[i]-'a'];
        int j = i;
        bool valid = true;
        while(j <= end){
            int c = s[j]-'a';
            if(first[c] < i) { valid = false; break; }
            end = max(end, last[c]);
            j++;
        }

        pair<int,int> best = skip; // default: not take
        if(valid){
            pair<int,int> rest = f(end+1, s);
            pair<int,int> take = {1 + rest.first, (end-i+1) + rest.second};
            // prefer more substrings; tie -> smaller length
            if(take.first > best.first || (take.first == best.first && take.second < best.second))
                best = take;
        }

        computed[i] = true;
        memo[i] = best;
        return best;
    }

    vector<string> maxNumOfSubstrings(string s) {
        n = s.size();
        first.assign(26, -1);
        last.assign(26, -1);
        for(int i = 0; i < n; i++){
            int c = s[i]-'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }

        memo.assign(n, {0,0});
        computed.assign(n, false);
        f(0, s); // fills memo for every index

        // reconstruct the actual chosen substrings by re-deriving decisions
        vector<string> ans;
        int i = 0;
        while(i < n){
            pair<int,int> skip = (i+1 <= n) ? f(i+1, s) : make_pair(0,0);

            int end = last[s[i]-'a'];
            int j = i;
            bool valid = true;
            while(j <= end){
                int c = s[j]-'a';
                if(first[c] < i) { valid = false; break; }
                end = max(end, last[c]);
                j++;
            }

            bool tookTake = false;
            if(valid){
                pair<int,int> rest = f(end+1, s);
                pair<int,int> take = {1+rest.first, (end-i+1)+rest.second};
                if(take.first > skip.first || (take.first == skip.first && take.second < skip.second)){
                    tookTake = true;
                }
            }

            if(tookTake){
                ans.push_back(s.substr(i, end-i+1));
                i = end+1;
            } else {
                i = i+1;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> ans;
//     int maxi = INT_MIN;
//     void f(int i, string &s, vector<int>& first, vector<int>& last, vector<string> temp)){
//         if (i >= s.size()) {
//             if (temp.size() > maxi ||
//                 (temp.size() == maxi && totalLen(temp) < totalLen(ans)))
//                 ans = temp, maxi = temp.size();
//             return;
//         }

//         // non take
//         f(i + 1, s, first, last, temp);

//         int end = last[s[i] - 'a'];
//         int j = i;
//         bool valid = true;
//         while (j <= end) {
//             int c = s[j] - 'a';
//             if (first[c] < i) {
//                 valid = false;
//                 break;
//             }
//             end = max(end, last[c]);
//             j++;
//         }

//         if (temp.size() > maxi) {
//             ans = temp;
//             maxi = temp.size();
//         }

//         if (valid) {
//             temp.push_back(s.substr(i, end - i + 1));
//             f(end + 1, s, first, last, temp);
//             temp.pop_back();
//         }
//     }
//     vector<string> maxNumOfSubstrings(string s) {
//         int n = s.size();
//         unordered_map<char, int> lastseen;

//         for (int i = 0; i < n; i++) {
//             lastseen[s[i]] = i;
//         }
//         unordered_set<char> st;
//         vector<string> temp;
//         f(0, s, lastseen, st, temp);
//         return ans;
//     }
// };

