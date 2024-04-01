class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = 9999;
        for (auto s : strs) {
            if (m > s.length()) {
                m = s.length();
            }
        }
        
        int index = 0;
        string result = "";
        int chk = 0;
        while (1) {
            if (index >= m) {
                break;
            }
            char cret = strs[0][index];
            for (auto s : strs) {
                if (s[index] != cret) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 1) {
                break;
            } else {
                result += cret;
            }
            index++;
        }
        
        return result;
    }
};