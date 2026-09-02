class Solution {
public:
    bool validPalindrome(string s) {
        size_t left {0};
        size_t right {s.size()-1};

        while (left < right) {
            if (s[left] != s[right]) {
                string skipLeft = s.substr(left+1, right-left);
                string skipRight = s.substr(left, right-left);
                return skipLeft == string(skipLeft.rbegin(), skipLeft.rend()) || skipRight == string(skipRight.rbegin(), skipRight.rend());
            }
            ++left;
            --right;
        }

        return true;
    }
    
};