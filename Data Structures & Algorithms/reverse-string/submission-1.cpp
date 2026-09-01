class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t left {0};
        size_t right {s.size()-1};

        while (left < right) {
            char tmp {s[left]};
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};