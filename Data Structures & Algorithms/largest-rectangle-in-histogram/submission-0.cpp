class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        s.push(-1);
        //[2,1,5,6,2,3]
        // i = 0, h[0] = 2
        // s = [-1, 0]
        // i = 1, h[1] = 1
        // heights[s.top] = 2 > h[0] = 1,　go to else
        // h = 1 * 2 = 2
        // res = 2
        // s = [-1, 1]
        // i = 2, h[2] = 5
        // heights[s.top] = 1 < h[2] = 5
        // s = [-1, 1, 2]
        // i = 3, h[3] = 6
        // heights[s.top] = 5 < h[3] = 6
        // s = [-1, 1, 2, 3]
        // i = 4, h[4] = 2
        // heights[s.top] = 6 > h[4] = 2, go to else
        // h = (4 - 3) * 6 = 6
        // res = 6
        // s = [-1, 1, 2]
        // heights[s.top] = 5 > h[4] = 2, while continue
        // h = (4-2) * 5 = 10
        // res = 10
        // s = [-1, 1]
        // heights[s.top] = 1 < h[4] = 2, end while
        // s = [-1, 1, 4]
        // i = 5, h[5] = 3
        // heights[s.top] = 1 < h[5]
        // s = [-1, 1, 4, 5]
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(s.top() != -1 && heights[i] < heights[s.top()]){
                int idx = s.top();
                s.pop();
                int width = i - s.top() - 1;
                int area = heights[idx] * width;
                res = max(res, area);
            }
            s.push(i);
        }
        while(s.top() != -1){
            int idx = s.top();
            s.pop();
            int width = n - s.top() - 1;
            int area = heights[idx] * width;
            res = max(res, area);
        }
        return res;
    }
};
