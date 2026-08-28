class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens){
            if( token != "+" && 
                token != "-" &&
                token != "*" &&
                token != "/"){
                    s.push(stoi(token));
                }
            else{
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                if(token == "+"){
                    s.push(left + right);
                }else if(token == "-"){
                    s.push(left - right);
                }else if(token == "*"){
                    s.push(left * right);
                }else if(token == "/"){
                    s.push(left / right);
                }
            }
        }
        return s.top();
    }
};
