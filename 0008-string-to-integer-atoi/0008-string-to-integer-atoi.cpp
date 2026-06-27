class Solution {
private:
    long long parse(string &s, int i, long long num, int sign) {
        // Stop if end of string or not a digit
        if (i >= s.size() || !isdigit(s[i]))
            return num;

        int digit = s[i] - '0';

        // Check overflow before adding digit
        if (sign == 1) {
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7))
                return (long long)INT_MAX + 1;
        } else {
            if (num > (long long)INT_MAX / 10 ||
                (num == (long long)INT_MAX / 10 && digit > 8))
                return (long long)INT_MAX + 1;
        }

        return parse(s, i + 1, num * 10 + digit, sign);
    }

public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = parse(s, i, 0, sign);

        // Clamp result
        if (sign == 1) {
            if (num > INT_MAX)
                return INT_MAX;
            return (int)num;
        } else {
            if (num > (long long)INT_MAX + 1)
                return INT_MIN;

            long long result = -num;

            if (result < INT_MIN)
                return INT_MIN;

            return (int)result;
        }
    }
};