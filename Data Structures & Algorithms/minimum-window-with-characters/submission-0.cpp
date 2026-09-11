class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for(auto& c:t){
            need[c]++;
        }
        int required = need.size();

        int minLen = INT_MAX;
        int minIndex = 0;
        int left = 0;
        int formed = 0;
        unordered_map<char, int> window;

        for(int right = 0; right < s.size(); right++){
            window[s[right]]++;
            if(window[s[right]] == need[s[right]]){
                formed++;
            }
            while(required == formed){
                if(minLen > (right - left + 1)){
                    minLen = right - left + 1;
                    minIndex = left;
                }
                window[s[left]]--;
                if(need[s[left]] > window[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        return minLen != INT_MAX ? s.substr(minIndex, minLen) : "";
    }
};
