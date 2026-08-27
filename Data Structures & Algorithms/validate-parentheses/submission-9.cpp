class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char ch:s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(pairs.contains(ch)){
                if(st.empty() || st.top() != pairs[ch]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
