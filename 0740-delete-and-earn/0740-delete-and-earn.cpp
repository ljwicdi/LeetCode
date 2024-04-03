class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //  maximum number of points 
        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(nums[i]) == myMap.end()) {
                myMap[nums[i]] = 1;
            } else {
                myMap[nums[i]]++;
            }
        }
        
        if (myMap.size() == 1) return nums[0] * myMap[nums[0]];
        if (myMap.size() == 2) {
            vector<pair<int, int>> v(myMap.begin(), myMap.end());
            if (abs(v[0].first - v[1].first) == 1) {
                return max(v[0].first * v[0].second, v[1].first * v[1].second);
            } else {
                return v[0].first * v[0].second + v[1].first * v[1].second;
            }
        }
        
        // size >= 3
        int dp[myMap.size()];
        vector<pair<int, int>> temp(myMap.begin(), myMap.end());
        dp[0] = temp[0].first * temp[0].second;
        if (temp[1].first - temp[0].first == 1) {
            dp[1] = temp[1].first * temp[1].second;
        } else {
            dp[1] = temp[0].first * temp[0].second + temp[1].first * temp[1].second;
        }
        
        if (temp[2].first - temp[1].first == 1) {
            dp[2] = dp[0] + temp[2].first * temp[2].second;
        } else {
            dp[2] = max(dp[1], dp[0]) + temp[2].first * temp[2].second; 
        }
        
        
        for (int i = 3; i < temp.size(); i++) {
            if (temp[i].first - temp[i - 1].first == 1) {
                dp[i] = max(dp[i - 2], dp[i - 3]) + temp[i].first * temp[i].second;
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2]) + temp[i].first * temp[i].second;
            }
        }
        
        return max(dp[temp.size() - 1], dp[temp.size() - 2]);
    }
};