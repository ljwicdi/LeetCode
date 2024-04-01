class Solution {
public:
    int romanToInt(string s) {
        map<char, int> myMap;
        myMap['I'] = 1; myMap['V'] = 5; myMap['X'] = 10; myMap['L'] = 50;
        myMap['C'] = 100; myMap['D'] = 500; myMap['M'] = 1000;
        
        int result = 0, index = 0;
        while (1) {
            if (index >= s.length()) {
                break;
            }
            if (s[index] == 'I') {
                if (index + 1 <= s.length() - 1) {
                    if (s[index + 1] == 'V') {
                        result = result + 4;
                        index = index + 2;
                    
                    } else if (s[index + 1] == 'X') {
                        result = result + 9;
                        index = index + 2;
                    } else {
                        result = result + 1;
                        index = index + 1;
                    }
                    continue;
                } else {
                    result = result + 1;
                    break;
                }
            } else if (s[index] == 'X') {
                if (index + 1 <= s.length() - 1) {
                    if (s[index + 1] == 'L') {
                        result = result + 40;
                        index = index + 2;
                    
                    } else if (s[index + 1] == 'C') {
                        result = result + 90;
                        index = index + 2;
                    } else {
                        result = result + 10;
                        index = index + 1;
                    }
                    continue;
                } else {
                    result = result + 10;
                    break;
                }
            } else if (s[index] == 'C') {
                if (index + 1 <= s.length() - 1) {
                    if (s[index + 1] == 'D') {
                        result = result + 400;
                        index = index + 2;
                    
                    } else if (s[index + 1] == 'M') {
                        result = result + 900;
                        index = index + 2;
                    } else {
                        result = result + 100;
                        index = index + 1;
                    }
                    continue;
                } else {
                    result = result + 100;
                    break;
                }
            }
            
            result = result + myMap[s[index]];
            index++;
        }
        return result;
    }
};