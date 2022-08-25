class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int max_min = targetSeconds / 60;
        int seconds = targetSeconds - max_min * 60;
        // only two possible ways
        int solution1 = max_min * 100 + seconds;
        int solution2 = (max_min - 1) * 100 + seconds + 60;
        
        if (max_min > 99) {
            solution1 = -1;
        }
        if (seconds + 60 > 99) {
            solution2 = -1;
        }
        
        int cost1 = calculateCost(solution1, startAt, moveCost, pushCost, targetSeconds);
        int cost2 = calculateCost(solution2, startAt, moveCost, pushCost, targetSeconds);
        
        return min(cost1, cost2);
        
    }
    
    int calculateCost(int solution, int startAt, int moveCost, int pushCost, int targetSeconds) {
        if (solution == -1) return std::numeric_limits<int>::max();
        string s = std::to_string(solution);
        int curr_pos = startAt;
        int total_cost = 0;
        // go through each number and calculate cost
        for (int i = 0; i < s.length(); i++) {
            int curr_int = (int)s[i] - 48;
            if (curr_int != curr_pos) {
                total_cost += moveCost;
            }
            curr_pos = (int)s[i] - 48;
            total_cost += pushCost;
        }
        return total_cost;
    }
};