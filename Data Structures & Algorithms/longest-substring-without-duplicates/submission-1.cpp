class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool c[96] = {false};
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.length(); right++){
            int idx = s[right] - ' ';
            while(c[idx]){
                c[s[left] - ' '] = false;
                left++;
            }
            c[idx] = true;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
