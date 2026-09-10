class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int left = 0;
        int maxLen = 0;
        for(int right = 0;right < s.size(); right++){
            while(se.count(s[right])){
                se.erase(s[left]);
                left++;
            }
            se.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
