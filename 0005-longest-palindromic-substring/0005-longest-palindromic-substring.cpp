class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> check(s.length() + 1, vector<bool>(s.length() + 1, false));
        
        // 길이가 1인 문자는 펠린드롬
        for (int i = 0; i <= s.length(); i++) {
            check[i][i] = true;
        }
        
        int max = 1;
        pair<int, int> start_end;
        for (int i = s.length() - 1; i >= 1; i--) {
            int temp = s.length();
            int k = i;
            for (int j = 0; j < i; j++) {
                // 길이가 2인 문자열 
                if (temp - k == 1) {
                    if (s[k - 1] == s[temp - 1]) {
                        check[k][temp] = true;
                        if (max < 2) {
                            max = 2;
                            start_end = make_pair(k - 1, temp - 1);
                        } 
                    }
                    // 길이가 2보다 큰 문자열
                } else {
                    if (s[k - 1] == s[temp - 1]) {
                        if (check[k + 1][temp - 1] == true) {
                            check[k][temp] = true;
                            if (max < temp - k + 1) {
                                max = temp - k + 1;
                                start_end = make_pair(k -1 , temp - 1);
                            }
                        }
                    }
                }
                temp--;
                k--;
            }
        }
        
        // 가장 긴 부분문자열을 찾자
        int start = start_end.first;
        int end = start_end.second;
        string answer = "";
        for (int i = start; i <= end; i++) {
            answer += s[i];
        }
        return answer;
        
    }
};