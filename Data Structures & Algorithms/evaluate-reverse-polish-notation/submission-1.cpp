class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const string& token : tokens){
            if( token == "+" || token == "-" || token == "*" || token == "/"){
                    int f2 = s.top(); s.pop();
                    int f1 = s.top();s.pop();
                    if (token == "+") s.push(f1 + f2);
                    else if(token == "-") s.push(f1 - f2);
                    else if(token == "*") s.push(f1 * f2);
                    else if(token == "/") s.push(f1 / f2);
                }else{
                    s.push(stoi(token));
                }
        }
        return s.top();
    }
};
