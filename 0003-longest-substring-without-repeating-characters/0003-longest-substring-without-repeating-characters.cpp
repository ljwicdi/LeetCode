class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        if (s.length() == 0) return 0;
        int m = 0;
        while (1) {
            map<char, int> myMap;
            int cnt = 0;
            while (1) {
                
                if (myMap.find(s[index]) != myMap.end()) {
                    if (cnt > m) {
                        m = cnt;
                    }
                    index = myMap[s[index]] + 1;
                    break;
                }
                myMap[s[index]] = index;
                cnt++;
                index++;
                if (index >= s.length()) {
                    if (cnt > m) {
                        m = cnt;
                    }
                    break;
                }
            }
            if (index >= s.length()) break;
        }
        
        return m;
    }
};