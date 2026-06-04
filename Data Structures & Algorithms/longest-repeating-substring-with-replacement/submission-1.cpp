class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        for(int right = 0; right < s.length(); right++){
            count[s[right] - 'A']++;
            // 紀錄出現頻率最高的字
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            // 計算視窗大小 - 頻率最高的字 = 留下剩餘要改動的字
            // 改動的字比k大, 就要讓視窗變小
            while((right - left + 1) - maxFreq > k){
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
