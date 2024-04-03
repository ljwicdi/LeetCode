class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        
        int dp1[cost.size() + 1];
        dp1[0] = cost[0];
        dp1[1] = cost[0] + cost[1];
        for (int i = 2; i <= cost.size() - 1; i++) {
            dp1[i] = min(dp1[i - 1], dp1[i - 2]) + cost[i];
        }
        
        int dp2[cost.size() + 1];
        dp2[1] = cost[1];
        dp2[2] = cost[1] + cost[2];
        for (int i = 3; i <= cost.size() - 1; i++) {
            dp2[i] = min(dp2[i - 1], dp2[i - 2]) + cost[i];
        }
        
        return min(min(dp1[cost.size() - 2], dp1[cost.size() - 1]), min(dp2[cost.size() - 2], dp2[cost.size() - 1]));
    }
};