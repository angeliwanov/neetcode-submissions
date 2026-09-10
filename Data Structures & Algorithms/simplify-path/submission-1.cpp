class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss (path);
        vector<string> cleaned_path;
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir != "" && dir != ".") {
                cleaned_path.emplace_back(dir);
            }            
        }

        vector<string> stk;
        for (const auto& dir: cleaned_path) {            
            if (dir == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                } 
            }
            else {
                stk.emplace_back(dir);
            }
            
        }

        string res = "/";
        for (size_t i = 0; i < stk.size(); ++i) {            
            res += stk[i];
            if (i != stk.size() - 1) {
                res += "/";
            }
        }
        return res;
    }
};