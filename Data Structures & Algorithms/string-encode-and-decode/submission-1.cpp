class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const auto& str: strs) {        
            // encode num of char red, delimiter # and the string                
            res += to_string(str.size()) + "#" + str;            
        }        
        cout << res << '\n';
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i {0};

        while (i < s.size()) {
            string str;
            string count;
            // take the count
            while (s[i] != '#') {
                count += s[i++];
            }
            // skip over #
            ++i;
            // read the string
            for (int j = 0; j < stoi(count); ++j) {
                str += s[i++];                
            }
            // append it to the list
            res.push_back(str);
        }

        return res;
    }
};
