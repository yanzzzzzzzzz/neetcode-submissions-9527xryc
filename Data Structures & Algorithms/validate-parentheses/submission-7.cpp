class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(ch == ')' || ch == ']' || ch == '}'){
                if(st.empty() || st.top() != pairs[ch]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
