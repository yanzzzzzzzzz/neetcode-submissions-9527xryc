class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cars;
        for(int i = 0; i < speed.size(); i++){
            cars.push_back(make_pair(position[i], speed[i]));
            sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        }
        double lastTime = 0, fleet = 0;
        for(int i = 0; i < cars.size(); i++){
            double t = (double)(target - cars[i].first) / cars[i].second; // 跟終點的距離 / 速度
            if(t > lastTime){
                fleet++;
                lastTime = t;
            }
        }
        return fleet;
    }
};
