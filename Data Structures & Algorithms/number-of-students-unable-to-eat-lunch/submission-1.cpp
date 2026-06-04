class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> q;

        for (const auto& student: students) {
            q.push(student);
        }

        for (const auto& sandwich: sandwiches) {
            int length = q.size();
            while (length and q.front() != sandwich) {
                q.push(q.front());
                q.pop();
                --length;
            }
            if (q.front() == sandwich) {
                q.pop();
            } else {
                break;
            }
        }


        return q.size();
    }
};