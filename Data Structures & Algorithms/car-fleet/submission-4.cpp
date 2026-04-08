class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 用POS排序車子, 然後計算每台車的時間, 開始檢查車子是否要合併成車隊
        vector<pair<int, int>> cars;
        for(int i = 0; i < speed.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        double lastTime = 0;
        int fleet=0;
        for(int i = 0; i < speed.size(); i++){
            double t = (double)(target - cars[i].first) / cars[i].second;//時間=距離/速度
            if(t > lastTime){
                lastTime = t;
                fleet++;
            }
        }
        return fleet;
    }
};
