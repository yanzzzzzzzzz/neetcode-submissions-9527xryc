class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l <= r){
            int mid = ( l + r ) / 2;
            int hours = 0;
            for(int i = 0; i < piles.size();i++){
                hours += ceil((double)piles[i] / mid);
            }
            if(hours > h){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};
