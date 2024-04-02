class Solution {
public:
    int divide(int dividend, int divisor) {
        long result;
        long divid = (long) dividend;
        long divis = (long) divisor;
        result = (long) (divid / divis);

        if (result > INT_MAX) {
            return INT_MAX;
        }
        
        if (result < INT_MIN) {
            return INT_MIN;
        }
        
        return result;
    }
};