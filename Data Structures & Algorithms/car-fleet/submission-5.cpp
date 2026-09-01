class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // first 由大到小
            }
            return a.second > b.second;   // first 相同時，second 由大到小
        });

        double prevTime = 0;
        int fleets = 0;
        for(auto& car: cars){
            double time = (double)(target - car.first) / car.second;
            if(time > prevTime){
                fleets++;
                prevTime = time;
            }
        }
        return fleets;
        
    }
};
