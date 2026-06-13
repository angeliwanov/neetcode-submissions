#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        size_t left{0};
        size_t right{s.length()-1};

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else if (tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }

        return true;
    }
};
