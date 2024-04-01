
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // <값, 인덱스> 
        map<int, pair<int, int>> myMap;
        
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(nums[i]) == myMap.end())
                myMap[nums[i]] = make_pair(i, -1200000000);
            else
                myMap[nums[i]].second = i;
        }
        
        int index;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(target - nums[i]) != myMap.end()) {
                if (target - nums[i] == nums[i]) {
                    if (myMap[target - nums[i]].second != -1200000000) {
                        if (myMap[nums[i]].first == i) {
                            index = myMap[nums[i]].second;
                            if (index < i) {
                                result.push_back(index);
                                result.push_back(i);
                            } else {
                                result.push_back(i);
                                result.push_back(index);
                            }
                        } else if (myMap[nums[i]].second == i) {
                            index = myMap[nums[i]].first;
                            if (index < i) {
                                result.push_back(index);
                                result.push_back(i);
                            } else {
                                result.push_back(i);
                                result.push_back(index);
                            }
                        }
                        break;
                    }
                } else {
                
                    index = myMap[target - nums[i]].first;
                    if (index < i) {
                        result.push_back(index);
                        result.push_back(i);
                    } else {
                        result.push_back(i);
                        result.push_back(index);
                    }
                    break;
                }
                
            }
        }
        return result;
    }
};